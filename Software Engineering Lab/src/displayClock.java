/*
 * Write a program to display a clock
 * using valueOf() method of String Class 
 * and using Calender Class to get the 
 * second, minutes and hours.
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 18/02/2015
 * Modules:
 * paint(): to create Java Applet
 * run(): to run the Thread
 * start():to create the thread
 * */
import java.applet.*;
import java.awt.*;
import java.util.*;
//Import necessary packages
public class displayClock extends Applet implements Runnable{
   Thread thread,thread1; //Declaring two threads
   public void start(){
      thread = new Thread(this);
      thread.start();//Starting a thread
   }
   public void run(){
      thread1 = Thread.currentThread(); //Renaming current thread as t1
      while(thread1 == thread){
         repaint();//Repaint Java applet
         try{
            thread1.sleep(1000); //Sleep for 1second
         }
         catch(InterruptedException e){
        	 System.out.println("Error: "+e.getMessage());
        	 //Reporting errors
         }
      }
   }
   public void paint(Graphics graph){
      Calendar cal = new GregorianCalendar();//Gregorian Calender Object
      String hour = String.valueOf(cal.get(Calendar.HOUR));//Calculating Hours 
      String minute = String.valueOf(cal.get(Calendar.MINUTE));//Calculating Minutes
      String second = String.valueOf(cal.get(Calendar.SECOND));//Calculating Seconds
      graph.drawString(hour + ":" + minute + ":" + second, 20, 30);
      //Drawing the Applet
   }
}