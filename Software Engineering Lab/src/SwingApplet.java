/*
 * Write a program to use Swing Applet in
 * Java by implementing ActionListener and 
 * by creating Jlabels. 
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 18/02/2015 
 * Modules:
 * init():Initializes the Java Applet
 * actionPerformed(): Links the button with the 
 * action to be performed
 * */

import javax.swing.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
//Import necessary packages
public class SwingApplet extends Applet implements ActionListener {
   TextField input,output;//Editable Text field
   Label label1,label2; //Labels for Applet
   Button b1;//Button in Applet
   JLabel lbl;
   int num, sum = 0;
   //Initialise the Applet
   public void init(){
      label1 = new Label("please enter number : ");
      add(label1);//Add text in the applet 
      label1.setBackground(Color.yellow);//Set Background Colour	
      label1.setForeground(Color.magenta);//Set Foreground Colour
      input = new TextField(5);
      add(input);//Add a text field for input of a number from user
      label2 = new Label("Sum : ");
      add(label2);//Add text in applet
      label2.setBackground(Color.yellow);
      label2.setForeground(Color.magenta);
      output = new TextField(20);
      add(output);//Add an output text field 
      b1 = new Button("Add");
      add(b1);//Add a button Add
      b1.addActionListener(this);//to implement ActionListener
      lbl = new JLabel("Swing Applet Example. ");
      add(lbl);//Add a jlabel
      setBackground(Color.yellow);
   }
   public void actionPerformed(ActionEvent ae){
      try{
         num = Integer.parseInt(input.getText());
         //Retrieve input from user
         sum = sum+num;
         //Add the result and store it in sum
         input.setText("");
         //Input field is turned empty
         output.setText(Integer.toString(sum));
         //Result is set in output field
         lbl.setForeground(Color.blue);
         lbl.setText("Output of the second Text Box : " + output.getText());
      }
      catch(NumberFormatException e){
    	  //In case of Invalid Input
         lbl.setForeground(Color.red);
         lbl.setText("Invalid Entry!");
      }
   }  
}
