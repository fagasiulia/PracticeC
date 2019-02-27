import java.io.*;
import java.util.regex.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		String testString = "This is a test 2012-11-27";
		
		//Patterns 
		String pattern = "(\\s*)([0-9]{4}-[0-1][0-9]-[1-3][0-9])(\\s*)"; 
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
	        stringYouWantToCheck = stringYouWantToCheck.replaceAll(pattern, replacement);
	        System.out.println(mt.group(0));
	        int patternLenGroup0 = mt.group(0).length();
	        System.out.println(mt.group(1));
	        int patternLenGroup1 = mt.group(1).length();
	        System.out.println(mt.group(2));
	        int patternLenGroup2 = mt.group(2).length();
	        
	        StringBuffer newString = "";
	        int length = patternLenGroup1 - (replacement.length());
            if (length > 0){
                newString = alignedText(length);
            }
            else if (length < 0){
                int newLength = mt.length() - (patternLenGroup0 + replacement.length())
                newString = alignedText (patternLenGroup0);
            }
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
