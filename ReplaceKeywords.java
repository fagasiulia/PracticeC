import java.util.*;
import java.io.*;

public class ReplaceKeywords
{
	public static void main(String[] args) {
	    
		Scanner sourceFile;
		Scanner targetFile;
		boolean sourceFileExists = false;
		boolean targetFileExists = false;
		String oldCity = "Höhenkirchen";
		String newCity = "Timisoare";
		String oldDate =  "2013-02-13";
		String newDate = new SimpleDateFormat("yyyy-MM-dd").format(Calendar.getInstance());
		
		//Check if the source file exists
		try{
		  sourceFile = new Scanner(new File("source.txt"));  
		  sourceFileExists = true;
		}
		catch(Exception e){
		    System.out.println("Source file not found");
		}
		
		//Check if the target file exists
		try{
		  targetFile = new Scanner(new File("target.txt"));
		  targetFileExists = true;
		}
		catch(Exception e){
		    System.out.println("Target file not found");
		}
		
		//Create input and output files
		if (sourceFileExists && targetFileExists){
		  try(
		    Scanner input = new Scanner(sourceFile);
		    PrintWriter output = new PrintWriter(targetFile);){
		        
		        while(input.hasNext()){
		            String s1 = input.nextLine();
		            String s2 = s1.replaceAll(oldCity, newCity);
		            s2 = replaceAll (oldDate, newDate);
		            output.orintln(s2);
		        }
		    }		    
		}
	}
}

