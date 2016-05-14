/*
 * Write a program to compare the performance of 
 * two Strings created in 2 different ways
 *  Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 21/01/2015
 * */

import java.util.Scanner;
public class StringPerformance {
		   public static void main(String[] args){      
			   	  String wordLiteral,string,wordObject;
			      //Storing starting time of a String Object
					 Scanner input=new Scanner(System.in);//Input through Scanner Class
			   	  System.out.println("Enter a string");
			      string=input.next();
			   	  long startTime = System.currentTimeMillis();
	  				  for(int i=0;i<50000;i++){
			          wordLiteral = string;
    			      //word refer to string literals
		      }
		      long endTime = System.currentTimeMillis();
		      //Storing Ending time for creating the same string literal
		      System.out.println("Time taken for creation" 
		      + " of String literals : "+ (endTime - startTime) 
		      + " milli seconds ");        
		      long startTime1 = System.currentTimeMillis();
		      //Storing starting time of another String Object
		      for(int i=0;i<50000;i++){
		         wordObject = new String(string);
		       }
		      long endTime1 = System.currentTimeMillis();
 		      //Storing Ending time for creating string objects
		      System.out.println("Time taken for creation" 
		      + " of String objects : " + (endTime1 - startTime1)
		      + " milli seconds");
		   }
}
