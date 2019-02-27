import java.io.*;
import java.util.regex.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		
		String testString = "This is a test 2012-11-27";
		String pattern = "(\\s*)([0-9]{4}-[0-1][0-9]-[1-3][0-9])(\\s*)"; //Date pattern
		String cityPattern = "";
		String test = replaceKeywords (testString, pattern, " Date");
		System.out.println(test);
		
	}
	public static String replaceKeywords(String stringYouWantToCheck, String pattern, String replacement){
	    Pattern pw = Pattern.compile(pattern);
	    Matcher mt = pw.matcher(stringYouWantToCheck);
	   // int patternLen = mt.group(0).length();
	    //int replacementLen = replacement.length();
	    
	    System.out.println(mt.group(0).length());
	    
	    if(mt.find()){
	        stringYouWantToCheck = stringYouWantToCheck.replaceAll(pattern, replacement);
	    }
	    return stringYouWantToCheck;
	}
}
