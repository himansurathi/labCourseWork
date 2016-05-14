/*
 * Write a program to convert infix
 * to postfix expression by concept of stack
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 18/02/2015
 * Modules:
 * doTranformation(): Converts an infix string to postfix one
 * gotOperator(): for deciding precedence of Operators
 * gotparent(): for handling opening and closing braces
 * push(): Push elements into stack
 * pop(): Pop Elements from stack
 * peek(): Retrieve an element from stack
 * isEmpty(): Check if stack is empty
 * */

import java.io.IOException;
import java.util.Scanner;

public class InfixtoPostfix {
   private Stack StackBuffer; //Buffer Stack
   private String input; //Takes String as input
   private String output = "";//Stores Output
   public InfixtoPostfix(String in) {
      /* Parameterized Constructor*/
	  input = in;
      int stackSize = input.length();
      StackBuffer = new Stack(stackSize);
   }
   public String doTransformation() {
      for (int iterator = 0; iterator < input.length(); iterator++) {
         char ch = input.charAt(iterator);//Take a character frm input String
         switch (ch) {
         /* Match character with operator Symbol or ( or ) */
            case '+': 
            case '-':
            	gotOperator(ch, 1); 
            	break; 
            case '*': 
            case '/':
	            gotOperator(ch, 2); //Set Precedence of Operators
	            break; 
	        case '(': 
	        	StackBuffer.push(ch);
	        	break;
            case ')': 
            	gotParent(ch); //Set Parent
            	break;
            default: 
            	output = output + ch; 
            	break;
         }
      }
      while (!StackBuffer.isEmpty()) {
         output = output + StackBuffer.pop();
      }
      return output; 
   }
   public void gotOperator(char opThis, int prec1) {
      while (!StackBuffer.isEmpty()) {
         char opTop = StackBuffer.pop();
         if (opTop == '(') {
        	//Push if character is an opening bracket into stack
            StackBuffer.push(opTop); 
            break;
         }
         else {
        	//Set Priority of Operators
            int prec2;
            if (opTop == '+' || opTop == '-')
            	prec2 = 1;
            else
            	prec2 = 2;
            if (prec2 < prec1) { 
               StackBuffer.push(opTop);
               break;
            }
		    else
            output = output + opTop;
         }
      }
      StackBuffer.push(opThis); //Push into Buffer Stack
   }
   public void gotParent(char ch){ 
      while (!StackBuffer.isEmpty()) {
         char chx = StackBuffer.pop();
         if (chx == '(')  //Opening bracket check
        	 break; 
         else
        	 output = output + chx; 
      }
   }
   public static void main(String[] args) throws IOException {
	  Scanner scan=new Scanner(System.in);//Scanner Class
	  System.out.println("Enter an Expression");
	  String input = scan.next();//Taking Infix Expression as input
      String output;
      InfixtoPostfix theTrans = new InfixtoPostfix(input);
      if(input.charAt(input.length()-1)=='+' ||input.charAt(input.length()-1)=='-' ||
    	 input.charAt(input.length()-1)=='*' ||input.charAt(input.length()-1)=='/' )
    	  System.out.println("It is not a valid Infix expression");
      //Checking validity of Expression
      else{
    	  output = theTrans.doTransformation(); 
    	  System.out.println("Postfix Expression is " + output + '\n');
    	  //Final Postfix Expression
      }
   }
   //Implementing own Stack
   class Stack {
      private int maxSize;//max size
      private char[] stackArray; //character array
      private int top;
      public Stack(int max) {
         maxSize = max;
         stackArray = new char[maxSize];
         top = -1;
      }
      public void push(char iterator) {
         stackArray[++top] = iterator; //pushing elements into stack
      }
      public char pop() {
         return stackArray[top--]; //popping elemnts from stack
      }
      public char peek() {
         return stackArray[top]; //Retrieving elements from stack
      }
      public boolean isEmpty() {
         return (top == -1); //Check if Stack is Empty
     }
   }
}