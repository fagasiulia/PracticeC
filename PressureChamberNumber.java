import java.io.*;
import java.text.SimpleDateFormat;
import java.util.regex.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		String toCheck = "Pressure_Chamber_15";
		String pattern = "(Pressure_Chamber_)(\\d*)";
		String n = replaceKeywords(toCheck, pattern);
		System.out.println(n);
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
	    //If a match if found do this... 
	    if(mt.find()){
	        String word = mt.group(1);
	        String number = mt.group(2);
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
	        word = word + hexNumber + alignedText(repLength - hexNumberLength);
	    }
	    else{
	        word = word + hexNumber;
	    }
	    return word;
	}
}
