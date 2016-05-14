/*
 * Write a program to implement the
 * multiple inheritance in JAVA
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 21/01/2015
 * */

import java.util.Scanner;

//Creating an Interface to inherit same methods with different functionalities
interface Transaction {
     int BALANCE = 500;
     //Storing Balance
     Object transaction(Object input);
}

//Class CurrentAccount
class CurrentAccount implements Transaction {
     int bal;
     public Object transaction(Object input) {
         if(BALANCE>=(int)input){
    	 this.bal = BALANCE - (int)input;
         }
         else{
        	 System.out.println("You need to have "+((int)input-BALANCE)+" amount in bank");
         }
         // Withdrawing Balance from Current Account
         return bal;
     }
     public String toString() { 
    	 return "Current account"; 
    	 //Returning Current Account Message
     }
}
//Class SavingsAccount
class SavingsAccount implements Transaction {
     public Object transaction(Object input) {
         int result = BALANCE + (int)input;
         //Depositing Money to Savings Account
         return result;
     }
     public String toString() { 
    	 return "Savings account"; 
    	 //Returning Savings Account Message
     }
}

public class MultipleInheritance {
	 // Displaying Payment Information
      public static void payment(Transaction money, Object input) {
         System.out.println(money + " is debited:   " +  money.transaction(input));
     }
 	 // Displaying Deposit Information
     public static void deposit(Transaction money, Object input) {
         System.out.println(money + " is credited:   " +  money.transaction(input));
     }
     //Calling Deposit and Payment methods to display transactions
         public static void main(String[] args) {
		 Scanner input=new Scanner(System.in);//Input through Scanner Class
		 System.out.println("You have Rs 500 in account"); 
		 System.out.println("Enter the amount to be withdrawed");
		 int amount = input.nextInt();
		 //Enter the amount 
		 CurrentAccount deposit=new CurrentAccount();
		 payment(deposit, amount);
		 //Withdraw the amount from bank
		 System.out.println("Enter the amount to be deposited");
		 amount = input.nextInt();
	     deposit(new SavingsAccount(), amount);
         //Deposit the amount  bank
     }
}//End of Class
