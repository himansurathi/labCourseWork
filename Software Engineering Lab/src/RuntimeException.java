/*
 * Write a program to demonstrate how to 
 * use finally block to catch runtime exceptions
 * (Illegal Argument Exception) by the use of 
 * exception.getMessage()
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 21/01/2015
 * Modules:
 * runtime() Create Objects and Report Errors if not successfully Created
 * makeObject() Create an object if possible
 * */
import java.util.Scanner;

public class RuntimeException {
   public static void main(String[] argv) {
      new RuntimeException().runtime();
      //Creating a RunTimeException Object which calls doTheWork 
   }
   public void runtime() {
      Object object = null;
      //Creating a null object
      Scanner input=new Scanner(System.in);//Input through Scanner Class
      System.out.println("Enter a number less than equal to 5");
      int type=input.nextInt();
      //Input a number
      for (int iterator=0; iterator<5; iterator++) {
         try {
            object = makeObject(iterator,type);
            //Creating a new Valid Object
         }
         catch (IllegalArgumentException error) {
            System.err.println("Error: ("+ error.getMessage()+").\n");
            //Reporting error if Illegal Object is detected
            return;
         }
         finally {
            if (object==null){
            	System.exit(0);
                //Exiting the program if it is a null object
            	}
            System.out.println(object+" created.");//Printing Object 
         }
      }
   }
   //Creating an Object or Reporting Error
   public Object makeObject(int number,int type) throws IllegalArgumentException {
      if(type<0)
    	  throw new IllegalArgumentException("Negative value "+type+" is not allowed");
      //For negative values
      else if (type == number) {
      throw new IllegalArgumentException("Do not type " + type);
      //For Type 1 We throw an Exception
      }
      return new Object();
      //Else Return New Object
   }
}