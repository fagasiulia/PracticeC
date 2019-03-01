import java.io.*;
import java.text.SimpleDateFormat;
import java.util.regex.*;
import java.util.*;

public class Main {

	public static int decimalNumber = 0;
	public static void main(String[] args) {
		//Patterns 
		String datePattern = "(\\s*)([0-9]{4}-[0-1][0-9]-[1-3][0-9])(\\s*)"; 
		String cityKeyword = "Höhenkirchen";
		String cityPattern = "(\\s*)(Höhenkirchen)(\\s*)";
		String currentCity = "Timisoara";
		String pressureChamberPattern = "(\\s*)(\\.*)(Preasure_chamber_)(\\d*)(\\.*)(\\s*)";
        String ecuPattern ="(\\s*)(ECU_ADDRESS 0x)(E0\\d*\\w*\\d*)";
		
		//Get the date
		Date thisDate = new Date();
		SimpleDateFormat dateFormat =  new SimpleDateFormat("yyyy-MM-dd");
		String currentDate = dateFormat.format(thisDate);
		
		
		ArrayList<String> readFile = new ArrayList<String>();
		try(Scanner sourceFile = new Scanner(new File("a21.txt"));){
			while(sourceFile.hasNext()) {
				String s1 = sourceFile.nextLine();
	            String s2 = replaceKeywords(s1,datePattern, currentDate);
	            s2 = replaceKeywords(s2,cityPattern, currentCity);	 
	            s2 = replaceKeywords(s2,pressureChamberPattern);
	            s2 = ecuAddressComplement(s2,ecuPattern);
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
	//Method for replacing keywords within the test using a pattern
	public static String replaceKeywords(String stringYouWantToCheck, String pattern, String replacement){
	    Pattern pw = Pattern.compile(pattern);
	    Matcher mt = pw.matcher(stringYouWantToCheck);
	    
	    //If a match if found do this... 
	    if(mt.find()){
	    	//Get the length of each group
	    	
	    	// group(0) is for the full length
	        int patternLength = mt.group(0).length();
	        
	        // group(1) is for the space in front of the keyword
	        int firstGroupLength = mt.group(1).length();
	        
	        // group(2) is for the keyword
	        int secondGroupLength = mt.group(2).length();
	     
	        // group(3) is for the space after the keyword
	        int lastGroupLength = mt.group(3).length();
	        
	        //Create a StringBuffer to use for the space in front and after the keyword
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
	
	//Method for aligning the text
	public static StringBuffer alignedText(int length){
	    StringBuffer outputBuffer = new StringBuffer(length);
	    for(int i = 0; i < length; i++){
	        outputBuffer.append(" ");
	    }
	    return outputBuffer;
    }
	
    //Change Pressure Chamber's Number
	public static String replaceKeywords(String stringYouWantToCheck, String pattern){
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
	
	public static String pressureChamberNumberReplacement(String word, String number){
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
	
	//ECU_ADDRESS complement method
  public static String ecuAddressComplement(String stringYouWantToCheck, String pattern){
	    Pattern pw = Pattern.compile(pattern);
	    Matcher mt = pw.matcher(stringYouWantToCheck);
	    
	    String complement = stringYouWantToCheck;
	    //If a match is found do this...
	    if(mt.find()){
		//Get ECU_ADDRESS 
	        String string = mt.group(2);
		//Get the number
	        String stringNumber = mt.group(3);
	        long number = Long.parseLong(stringNumber,16);
		//Complement
	        long comp = ~number;
                //String to be returned
	        complement = mt.group(1) + string + (Long.toHexString(comp)).toUpperCase();
	    } 
	    return complement;
    }
    

}
