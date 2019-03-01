
public class Main
{
	public static void main(String[] args) {
	    String word = "Pressure_Chamber_";
	    String number = "11";
	    String finalString = pressureChamberNumberReplacement(word, number);
	    
		System.out.println(finalString);
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
	//Method for aligning the text
	public static StringBuffer alignedText(int length){
	    StringBuffer outputBuffer = new StringBuffer(length);
	    for(int i = 0; i < length; i++){
	        outputBuffer.append(" ");
	    }
	    return outputBuffer;
    }
}
