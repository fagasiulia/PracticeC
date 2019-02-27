import java.io.*;
import java.util.regex.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		
		String testString = "This is a test 2012-11-27";
		String pattern = "((?:(?:1[6-9]|2[0-9])\\d{2})(-)(?:(?:(?:0[13578]|1[02])(-)31)|((0[1,3-9]|1[0-2])(-)(29|30))))|(?:(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00)))(-)02(-)29)|(?:(?:1[6-9]|2[0-9])\\d{2})(-)(?:(?:0[1-9])|(?:1[0-2]))(-)(?:0[1-9]|1\\d|2[0-8])";
		String test = replaceKeywords (testString, pattern, "Date");
		System.out.println(test);
		
	}
	public static String replaceKeywords(String stringYouWantToCheck, String pattern, String replacement){
	    Pattern pw = Pattern.compile(pattern);
	    Matcher mt = pw.matcher(stringYouWantToCheck);
	    
	    if(mt.find()){
	        stringYouWantToCheck = stringYouWantToCheck.replaceAll(pattern, replacement);
	    }
	    return stringYouWantToCheck;
	}
}
