/*
 * Design a login application using database
 * and swing application. It connects to mysql 
 * and validates the username and password 
 * Written by Himansu Rathi(12/CS/06) on 17/03/2015
 * */
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.sql.*;
//Import necessary packages
public class LoginApplication extends JFrame
{
    //declaring our swing components
    JLabel l_name,l_pass;//A label for username and password to display in dialog box
    JTextField t_name;	//An editable text field for username
    JPasswordField t_pass; //A special JTextField but hides input text
    JButton button; //Login Button
    Container c; //To store 
    //a inner class to handling ActionEvents
    handler handle;
    //a separate class for processing database connection and authentication
    database db;
    LoginApplication()
    {
        //To get the Canvas Ready
    	super("Login form");//Display text
        c=getContentPane();
        c.setLayout(new FlowLayout()); 
        //extra classes
        db=new database();
        handle =new handler(); 
        //swing components
        l_name=new JLabel("Username");
        l_pass=new JLabel("Password");
        t_name=new JTextField(10);
        t_pass=new JPasswordField(10);
        button=new JButton("Login");
        //adding actionlistener to the button
        button.addActionListener(handle);
        //add to container
        c.add(l_name);
        c.add(t_name);
        c.add(l_pass);
        c.add(t_pass);
        c.add(button);
        //visual Parameters
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(200,130);
    }
    public static void main(String args[])
    {
        LoginApplication sample=new LoginApplication();
    }
    //an inner class .You can also write as a separate class
    class handler implements ActionListener
    {
        //must implement method
        //This is triggered whenever the user clicks the login button
        public void actionPerformed(ActionEvent ae)
        {
            //checks if the button clicked
            if(ae.getSource()==button)
            {
                char[] temp_pwd=t_pass.getPassword();
                String pwd=null;
                pwd=String.copyValueOf(temp_pwd);
                System.out.println("Username,Pwd:"+t_name.getText()+","+pwd);
                //The entered username and password are sent via "checkLogin()" which return boolean
                if(db.checkLogin(t_name.getText(), pwd))
                {
                    //a pop-up box
                    JOptionPane.showMessageDialog(null, "You have logged in successfully","Success",
                                        JOptionPane.INFORMATION_MESSAGE);
                }
                else
                {
                    //a pop-up box
                    JOptionPane.showMessageDialog(null, "Login failed!","Failed!!",
                                        JOptionPane.ERROR_MESSAGE);
                }
            }//if
        }//method
    }//inner class
}//class

class database 
{
	   // JDBC driver name and database URL
	   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
	   static final String DB_URL = "jdbc:mysql://localhost:3306/testDb";
	   //  Database credentials
	   static final String USER = "username";
	   static final String PASS = "password";
	   Connection connection;	
	   PreparedStatement preparedstatement;
	   ResultSet result;
	   database()
	   {
		   try{
			   	//STEP 2: Register JDBC driver
			   	Class.forName(JDBC_DRIVER);//Checking whether JDBC driver is present
			   	System.out.println("JDBC Driver found");
			   	//STEP 3: Open a connection
		   		System.out.println("Connecting to database...");
		   		connection = DriverManager.getConnection(DB_URL, USER, PASS);
	      		//Connecting to the database
		   		preparedstatement = connection.prepareStatement("select * from biodata where uname=? and pwd=?");
		   		//To get all usernames and passwords
           }catch (Exception e) 
		   {
             System.out.println(e);
		   }
	   }
        //ip:username,password
        //return boolean
    public Boolean checkLogin(String uname,String pwd)
    {
        try {            
            preparedstatement.setString(1, uname); //this replaces the 1st  "?" in the query for username
            preparedstatement.setString(2, pwd);  //this replaces the 2st  "?" in the query for password
            
            //executes the prepared statement
            result=preparedstatement.executeQuery();
            if(result.next())
            {
                //TRUE iff the query founds any corresponding data
                return true;
            }
            else
            {
                return false;
            }
        } 
        catch (Exception e) {
            // TODO Auto-generated catch block
            System.out.println("Error while validating "+e);
            return false;
        }
    }
}