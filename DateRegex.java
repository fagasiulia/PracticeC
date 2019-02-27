package practice;

import java.io.*;
import java.util.regex.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		String testString = "This is a test 2012-11-27";
		
		//Patterns 
		String pattern = "(\\s*)([0-9]{4}-[0-1][0-9]-[1-3][0-9])(\\s*)"; 
		String city = "Timisoara";
		String cityPattern = "(\\s*)" + (city) + "(\\s*)";
		
		//Implement here
		String test = replaceKeywords (testString, pattern, " Date");
		System.out.println(test);
		
	}
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
