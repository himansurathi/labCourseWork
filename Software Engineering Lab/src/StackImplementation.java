/*
 *  Write a program to implement stack 
 *  stack by creating defined push()
 *  method for entering elements and
 *  pop() method for retrieving elements
 *  from stack.
 *  Written By Himansu Rathi (12/CS/06) and Vivek Verma(12/CS/04) on 18/02/2015
 *  Modules:
 *  showpush()-to push an element into stack
 *  showpop()-to pop an element from stack
 *   */


import java.util.Scanner;

class UserStack{
	   int stack[];//an array 
	   int top;//mark top of stack
	   int maxSize;//Capacity of stack
	   UserStack(int size){
		   /* Parameterized Constructor */
		   maxSize=size;
		   stack=new int[maxSize];
		   top=-1;
	   }
	   //Push an Element into Stack
	   public void showpush(int element) {
	      if(top+1==maxSize) //Check Overflow Condition
	    	  System.out.println("Stack Overflow");
	      else{
	    	  top++;
		      stack[top]=element; //Insert element into stack
	    	  System.out.println("The top of the stack is now at "+top+" position");
		      //Pushing Integers on stack
	      }
	   }
	   //Pop an Element from Stack
	   public void showpop() {
		  int value;
		  if(top==-1){ //Check UnderFlow Condition
			  System.out.println("Stack Underflow");
		  }
		  else{
			  value=stack[top];//Pop an element from stack
	    	  System.out.println("The element popped from stack is "+value);
	    	  top--;
		      System.out.println("The top of the stack is now at "+top+" position");
		  }
	   }
}
public class StackImplementation{
	public static void main(String args[]) {
		int size,number,choice;
		Scanner scan=new Scanner(System.in);
		try{
				System.out.println("Enter the size of stack");
				size=scan.nextInt(); //Size of Stack
				UserStack ustack=new UserStack(size); //create a stack of Required Size
				while(true){
					System.out.println("Enter 1 to push ,0 to pop and any other key to exit");
					choice=scan.nextInt();
					if(choice==1){
						System.out.println("Enter an element to be pushed into stack");
						number=scan.nextInt();
						ustack.showpush(number);//Push an element into stack
					}
					else if(choice==0){
						ustack.showpop();//Pop an element into stack
					}
					else{
						System.exit(0); //Exit from programs
					}
				}
			}
			catch(Exception e){
				System.out.println("Error occured "+e.getMessage());
				System.exit(0);
				//Error Occured during input
			}
	}
}