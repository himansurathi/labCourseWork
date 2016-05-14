/*
 * Write a program in java that converts an array 
 * into a Collection Arrays.asList(<name>) method
 * of Java Util Class
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 4/02/2015
 * Modules
 * displayCollections(Collection)- displays Elements of Collection
 * getinput(int,String)- takes the elements of Array as input  
 * */

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
// Import necessory packages

public class ArraysToCollection {
	//Convert Arrays to Collection
	public static void main(String[] args) {
		int n=getinput("Enter the size of Array\n"); 
		//Takes size of Array as Input
		Integer []Array=getinput(n,"Enter a number\n");
		//Takes Array as Input
		List <Integer> Collections=Arrays.asList(Array);
		//Converts Arrays to List Collection
		displayCollections(Collections);
		//Displays the List Connections
	}
	public static void displayCollections(List<Integer> Collect)
	{
		System.out.println("\nThe Elements in Collector are");
		for(Integer itr: Collect)
		{
			System.out.println(itr);
			//Displays the elements of Collection
		}
	}
	public static int getinput(String display)
	{
		System.out.println(display);
		Scanner scan=new Scanner(System.in);// Scanner object created
		int size=0;
		try{
			 size=scan.nextInt();
			 //Takes Input the size of Array
		}
		catch (Exception e) {
			System.err.println("An Exception was caught :"+ e.getMessage());
			System.exit(0);
			// A error thrown for invalid input
			}
		return size;
	}
	//Function Overloading getinput()
	public static Integer[] getinput(int size,String display)
	{
		Scanner scan=new Scanner(System.in);
		int itr=0;
		Integer[] arr=new Integer[size]; //Creates an empty Array of length=size 
		while(itr<size)
		{
			try{
   				System.out.println(display);
				 arr[itr]=scan.nextInt();
				 itr++;
				 //Takes each number as input to an element of Array.
			}
			catch (Exception e) {
				System.err.println("An Exception was caught : "+ e.getMessage());
				//Error for valid Input
				System.exit(0);
			}
		}
		return arr; // Returns Array
	}
}
