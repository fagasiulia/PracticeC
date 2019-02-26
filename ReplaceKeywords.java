import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;

public class ReadingFiles
{
	public static void main(String[] args) {
	    
		Scanner sourceFile = null;
		PrintWriter targetFile = null;
		boolean sourceFileExists = false;
		boolean targetFileExists = false;
		String oldCity = "Höhenkirchen";
		String newCity = "Timisoara";
		String oldDate =  "2013-02-13";
		Date thisDate = new Date();
		SimpleDateFormat dateFormat =  new SimpleDateFormat("yyyy-MM-dd");
		
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
		  try{
		        
		        while(sourceFile.hasNext()){
		            String s1 = sourceFile.nextLine();
		            String s2 = s1.replaceAll(oldCity, newCity);
		            s2 = s2.replaceAll (oldDate, dateFormat.format(thisDate));
		            targetFile.println(s2);
		        }
		    }catch(Exception e) {
		    	System.out.println("Failed to complete");
		    }finally{
		        sourceFile.close();
		        targetFile.close();
		    }			    
		}
	}
}

