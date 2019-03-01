import java.io.*;
import java.text.SimpleDateFormat;
import java.util.regex.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) {
		String test = "Test          \\";
		String pattern = "(\\s*)(Test)(\\s*)";
		String spaces = replaceKeywords(test, pattern, "Abca");
		//test = spaces + test;
		System.out.println(test);
		System.out.println(spaces);
	}
	public static StringBuffer alignedText(int length){
	    StringBuffer outputBuffer = new StringBuffer(length);
	    for(int i = 0; i < length; i++){
	        outputBuffer.append(" ");
	    }
	    return outputBuffer;
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
                if (length > 0){
                   newString = alignedText(length + lastGroupLength);
                }
		//If the length < 0 this means that the replacemnt word is longer and you need to subtract the difference from the space
		//after the keyword
                else if (length < 0){
                   newString = alignedText (lastGroupLength + length);
                }
		//If the length of the words is equal keep the same space
                else{
                   newString = alignedText(lastGroupLength);
                }
                replacement = alignedText(firstGroupLength) + replacement + newString;
                stringYouWantToCheck = stringYouWantToCheck.replaceAll(pattern, replacement);
	        }
	     
	    //Return the new string
	    return stringYouWantToCheck;
	}
	    
}
