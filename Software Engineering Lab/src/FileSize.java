/*
 * Write a program in Java to get the size 
 * of file in bytes by using file.exists()
 * and file.length() method of file class.
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 28/01/2015
 * Modules
 * getinput() - to get the Filename or path as input
 * getFileSize() -to calculate the FileSize
 */

import java.io.File;
import java.util.Scanner;
//Import necessary packages

public class FileSize {

	//Takes Path of File as Input and displays the length of file in bytes.
	public static void main(String[] args) {
		String path=getinput("Enter the path of file\n");
		long size=getFileSize(path);
		displaySize(size);
	}
	// it returns the path of File which is taken as Input
	public static String getinput(String display)
	{
		System.out.println(display);
		Scanner scan=new Scanner(System.in);//Input through scanner Class
		String pathFile=new String();
		try{
			 pathFile=new String(scan.nextLine());
			 //Storing the input as a String
		}
		catch(Exception e) {
			System.err.println("An Exception was caught :"+ e.getMessage());
			//Throws error for Invalid Input. 
			}
		finally{
			if(scan!=null)
				scan.close();
			//Closes scanner when it not null
		}
		return pathFile;
	}
	//Calculates the File Size in bytes
	public static long getFileSize(String path)
	{
	  File file=new File(path);
	  if(file.exists()==false || file.isFile()==false)
		  {
		    //Check if file does not exists and if the file is a Valid Input
		    System.out.println("Sorry, The File does not exists!!!!!");
		    System.exit(0);
		  }
	  return file.length(); //Returns length of file
	}
	
	public static void displaySize(long sizeFile)
	{
		System.out.println("The file is of length "+sizeFile);
	}
}
