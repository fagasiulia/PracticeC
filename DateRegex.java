package practice;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.regex.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		//Patterns 
		String datePattern = "(\\s*)([0-9]{4}-[0-1][0-9]-[1-3][0-9])(\\s*)"; 
		String cityKeyword = "Höhenkirchen";
		String cityPattern = "(\\s*)" + (cityKeyword) + "(\\s*)";
		
		//Get the date
		Date thisDate = new Date();
		SimpleDateFormat dateFormat =  new SimpleDateFormat("yyyy-MM-dd");
		String currentDate = dateFormat.format(thisDate);
		
		//Implement here	
		try(Scanner file = new Scanner(new File("C:\\Users\\fagas\\Desktop\\HTML\\sourceFile.txt")); 
			PrintWriter newFile = new PrintWriter(new File("C:\\Users\\fagas\\Desktop\\HTML\\sourceFile.txt")); ) {
			
	        while(file.hasNext()){
	            String s1 = file.nextLine();
	            String s2 = replaceKeywords(s1,datePattern, currentDate);
	            newFile.println(s2);
	        }
			
		}catch (Exception e) {
			System.out.println("Unable to execute");
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
	        StringBuffer newString = null;
	        int length = secondGroupLength - (replacement.length());
            if (length > 0){
                newString = alignedText(length);
            }
            else if (length < 0){
                int newLength = patternLength - (firstGroupLength + replacement.length());
                newString = alignedText (patternLength);
            }
            replacement = alignedText(mt.group(1).length()) + replacement + newString;
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
}





/** 
//Update file
public static PrintWriter updateFile(Scanner file, PrintWriter newFile, String stringYouWantToCheck, String pattern, String replacement) {
	ArrayList<String> fileArray = readFile(file);
	for(int i = 0; i  )
	return newFile;
}
//Read file
public static ArrayList<String> readFile(Scanner file){
	ArrayList<String> arrayListToReturn = new ArrayList<String>();
	while(file.hasNext()) {
		String s = file.nextLine();
		arrayListToReturn.add(s);
	}
	
	return arrayListToReturn;
}
**/
