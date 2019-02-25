import java.util.Scanner;
import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;

public class ReadingFiles
{
	public static void main(String[] args) {
	    
		Scanner sourceFile;
		PrintWriter targetFile;
		boolean sourceFileExists = false;
		boolean targetFileExists = false;
		String oldCity = "Höhenkirchen";
		String newCity = "Timisoare";
		String oldDate =  "2013-02-13";
		String newDate = new SimpleDateFormat("yyyy-MM-dd").format(Calendar.getInstance());
		
		//Check if the source file exists
		try{
		  sourceFile = new Scanner(new File("sourceFile.txt"));  
		  sourceFileExists = true;
		}
		catch(Exception e){
		    System.out.println("Source file not found");
		}
		
		//Check if the target file exists
		try{
		  targetFile = new PrintWriter(new File("targetFile.txt"));
		  targetFileExists = true;
		}
		catch(Exception e){
		    System.out.println("Target file not found");
		}
		
		//Create input and output files
		if (sourceFileExists && targetFileExists){
		  try(
		    Scanner input = sourceFile;
		    PrintWriter output = targetFile;){
		        
		        while(input.hasNext()){
		            String s1 = input.nextLine();
		            String s2 = s1.replaceAll(oldCity, newCity);
		            s2 = s1.replaceAll (oldDate, newDate);
		            output.println(s2);
		        }
		    }catch(Exception e) {
		    	System.out.println("Failed to complete");
		    }		    
		}
	}
}

