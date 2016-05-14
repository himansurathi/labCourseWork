/*
 * Write a program to demonstrate how to 
 * handle multiple exception methods by 
 * using System.err.println() method by System Class
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 21/01/2015
 * */
import java.util.Scanner;
public class MultipleException {
	 public static void main (String args[]) {
		 int sizeArray,iterator1,iterator2,position;
		 Scanner input=new Scanner(System.in);//Input through Scanner Class
	      System.out.println("Enter a element");
	     int num1=input.nextInt();
         System.out.println("Enter another element");
  	      int num2=input.nextInt();
  	      //Input two elements
  	      int result;
	      try {
    	         result = num1/num2;
    	         //dividing num1 with num2 and storing with result
    	         System.out.println("The result is " +result);
    			 System.out.println("Enter the size of Array (less than 3) ");
    			 sizeArray=input.nextInt();
    			 //Input size of Array
    			 int array[]=new int[sizeArray];
    	         System.out.println("Enter the elements of Array");
    		     //Input Elements of Array
     	  	      for(iterator1=0;iterator1<sizeArray;iterator1++)
    	 	    	 array[iterator1]=input.nextInt();
    	 	   	  //Take an array as Input
     	  	      System.out.println("Enter the position of the element in the Array");
     	  	      position=input.nextInt();
    	          System.out.println("The value of array is " +array[position]);
    	         //Print the array element at that position 
			   }
	      catch (ArrayIndexOutOfBoundsException e) {
	         System.out.println("Array Index is out of Bounds");
	         //Array Index out of Bounds
	      }
	      catch (ArithmeticException e) {
	         System.out.println ("Can't divide by Zero"+e);
	         //Cannot divide by zero
	      }
	   }
}
