import java.io.*;
import java.text.SimpleDateFormat;
import java.util.regex.*;
import java.util.*;

/*
Tema in 3 pasi:
1) sa modifici data si locatia in comentariu din 2013-02-13 in data curenta si Hohenkirchen in Timisoara

2) sa modifici numerotarea pressure chamber-urilor sa inceapa de la 0 si din decimal in hex,

3)  printezi in consola complement de 1 in format hexa pt fiecare ECU_ADDRESS

*/
public class Main
{
    
    public class ReplaceKeywords{
        public String replaceKeywords(String stringYouWantToCheck, String pattern, String replacement){
            Pattern pw = Pattern.compile(pattern);
	        Matcher mt = pw.matcher(stringYouWantToCheck);
	   
	        if(mt.find()){
	    	    int patternLength = mt.group(0).length();
	            int firstGroupLength = mt.group(1).length();
	            int secondGroupLength = mt.group(2).length();
	            int lastGroupLength = mt.group(3).length();
	            
	            StringBuffer newString = new StringBuffer("");
	            //Check the difference between the replacement word and the keyword
	            int length = secondGroupLength - (replacement.length());
	            //If the length > 0 this means that the replacement word is shorter so you need to complete its length with spaces
		        //If the length < 0 this means that the replacemnt word is longer and you need to subtract the difference from the space
		        //after the keyword
		        //If the length of the words is equal keep the same space
		        newString = alignedText(length + lastGroupLength);
                replacement = alignedText(firstGroupLength) + replacement + newString;
                stringYouWantToCheck = stringYouWantToCheck.replaceAll(pattern, replacement);
	        }
	        //Return the new string
	        return stringYouWantToCheck;
        }
        
 	    public StringBuffer alignedText(int length){
 	        StringBuffer outputBuffer = new StringBuffer(length);
 	        for(int i = 0; i < length; i++){
 	            outputBuffer.append(" ");
	        }
	        return outputBuffer;
 	    }
    }
    public class ReplaceDate extends ReplaceKeywords{
        private final String datePattern = "(\\s*)([0-9]{4}-[0-1][0-9]-[1-3][0-9])(\\s*)";
        private String currentDate;
        
        public ReplaceDate(){
            Date thisDate = new Date();
            SimpleDateFormat dateFormat =  new SimpleDateFormat("yyyy-MM-dd");
		    this.currentDate = dateFormat.format(thisDate);
        }
        public String getDatePattern(){
            return datePattern;
        }
        public String getCurrentDate(){
            return currentDate;
        }
        
    }
    public class ReplaceLocation extends ReplaceKeywords{
        private final String cityPattern = "(\\s*)(Höhenkirchen)(\\s*)";
		private String currentCity;
		
		public ReplaceLocation (String currentCity){
		    this.currentCity = currentCity;
		}
		public void setCurrentCity(String newCity){
		    this.currentCity = newCity;
		}
		public String getCityPattern(){
		    return cityPattern;
		}
		public String getCurrentCity(){
		    return currentCity;
		}
    }
    public class ReplacePressureChamberNumber{
        private final String pressureChamberPattern = "(\\s*)(\\.*)(Preasure_chamber_)(\\d+)(\\.*)(\\s*)";
        
        public ReplacePressureChamberNumber(){} 
        
        public String getPressureChamberPattern(){
            return pressureChamberPattern;
        }
        
        public String replaceKeywords(String stringYouWantToCheck, String pattern){
	    Pattern pw = Pattern.compile(pattern);
	    Matcher mt = pw.matcher(stringYouWantToCheck);
	    String string = stringYouWantToCheck;
	    //If a match is found do this... 
	    if(mt.find()){
	        String word = mt.group(3);
	        String number = mt.group(4);
            String replacement = pressureChamberNumberReplacement(word, number);
            string = stringYouWantToCheck.replaceAll(pattern, replacement);
	   }
	     
	    //Return the new string
	    return string;
	}
	    
	    public String pressureChamberNumberReplacement(String word, String number){
	        int repLength = number.length();
	        int decimalNumber = Integer.parseInt(number) - 1;
	        String hexNumber = Integer.toHexString(decimalNumber).toUpperCase();
	        int hexNumberLength = hexNumber.length();
	       
	        if(repLength > hexNumberLength){
	            word = word + hexNumber;
	        }
	        else{
	            word = word + hexNumber;
	        }
	        return word;
	        
	    }	
	    
    }
    public class EcuAddressComplement{
        private final String ecuPattern ="(\\s*)(ECU_ADDRESS 0x)(E0\\d*\\w*\\d*)";
        
        public EcuAddressComplement(){}
        
        public String getEcuPattern(){
            return ecuPattern;
        }
        
        public String ecuAddressComplement(String stringYouWantToCheck, String pattern){
            Pattern pw = Pattern.compile(pattern);
	        Matcher mt = pw.matcher(stringYouWantToCheck);
	    
	        String complement = stringYouWantToCheck;
	        //If a match is found do this...
	        if(mt.find()){
	            String string = mt.group(2);
	            String stringNumber = mt.group(3);
	            long number = Long.parseLong(stringNumber,16);
	            long comp = ~number;
	            String hexNumber = (Long.toHexString(comp)).toUpperCase();
	            hexNumber = hexNumber.substring(8);
	            complement = mt.group(1) + string + hexNumber;
	        } 
	        return complement;
        }
        
    }


	public static void main(String[] args) {
		Main obj = new Main();
		Main.ReplaceDate replaceDate1 = obj.new ReplaceDate();
		Main.ReplaceLocation replaceLocation = obj.new ReplaceLocation("Timisoara");
		Main.ReplacePressureChamberNumber replacePressureChamberNr = obj.new ReplacePressureChamberNumber();
		Main.EcuAddressComplement ecuAddress = obj.new EcuAddressComplement();
		
		ArrayList<String> readFile = new ArrayList<String>();
		
		try(Scanner sourceFile = new Scanner(new File("a21.txt"));){
			while(sourceFile.hasNext()) {
				String s1 = sourceFile.nextLine();
	            String s2 = replaceDate1.replaceKeywords(s1,replaceDate1.getDatePattern(), replaceDate1.getCurrentDate());
	            s2 = replaceLocation.replaceKeywords(s2,replaceLocation.getCityPattern(), replaceLocation.getCurrentCity());
	            s2 = ecuAddress.ecuAddressComplement(s2,ecuAddress.getEcuPattern());
	            
	            if(!readFile.contains("Preasure_chamber_A")){
	                try{
	                    s2 = replacePressureChamberNr.replaceKeywords(s2,replacePressureChamberNr.getPressureChamberPattern());	                
	                }catch (NumberFormatException e){
	                    e.printStackTrace();
	                }    
	            }
	            readFile.add(s2);
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
		
		try(PrintWriter finaleFile = new PrintWriter(new File("a21.txt"));){
			for(int i = 0; i < readFile.size(); i++) {
				String s = readFile.get(i);
				finaleFile.println(s);
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
}
