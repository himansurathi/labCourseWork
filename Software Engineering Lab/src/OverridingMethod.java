
/*
 * Write a program to demonstrate the way 
 * of method by subclass with different 
 * number and type of parameter.
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 21/01/2015
 * Modules
 * move(),bark()-actions performed by Animal and Dog Class
 * */

import java.util.Scanner;

class Animal{
	// Move Behaviour of Animal Class
	public void move(String action){
	      System.out.println("Animals can "+action);
	   }
	   //Bark method of Animal Class
	   public void bark(){
		   System.out.println("All animals cannot bark");
	   }
	}

class Dog extends Animal{
	   // Move Behaviour of Dog Class
	   public void move(String action){
	      System.out.println("Dogs can "+action);
	   }
	   //Bark method of Dog Class
	   public void bark(){
		   System.out.println("Dogs can bark");
	   }
	}

public class OverridingMethod{
   public static void main(String args[]){
		  String actionAnimal,actionDog;
		  Animal cow = new Animal(); // Animal reference and object
	      Animal bulldog = new Dog(); // Animal reference but Dog object
	      Scanner input=new Scanner(System.in);//Input through Scanner Class
	      System.out.println("Enter an action of Animal");
	      actionAnimal=input.next();
	      //Input for Animal Class
	      System.out.println("Enter an action of Dog");
	      actionDog=input.next();
	      //Input for Dog Class	      
	      cow.move(actionAnimal); //runs the method in Animal class
	      cow.bark();//runs the method in Animal Class
	      bulldog.move(actionDog); //Runs the method in Dog class
	      bulldog.bark();	//Runs the method in Dog child class
	      input.close();
	   }
	}