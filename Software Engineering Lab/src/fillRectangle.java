/*
 * Write a program to create an applet 
 * which will have fill colour in a rectangle 
 * using setColour(),fillRectangle() method 
 * of Graphics class to fill colour in a rectangle 
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 18/02/2015 
 * */
import java.applet.*;
import java.awt.*;
//Import necessary packages
public class  fillRectangle extends Applet{
   public void paint(Graphics graph){
      graph.drawRect(300,150,200,100);//Drawing a Rectangle in Applet
      graph.setColor(Color.yellow);//Set the colour to be yellow   
      graph.fillRect( 300,150, 200, 100 );//Fill the Rectangle with yellow colour
      graph.setColor(Color.red);
      graph.drawString("Rectangle",350,100);//Type text Rectangle in Applet
   }
}