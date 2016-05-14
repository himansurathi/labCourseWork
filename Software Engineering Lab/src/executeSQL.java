/*
 * Write a program to execute multiple SQL commands 
 * on a database simultaneously. Use addBatch and 
 * executeBatch commands to execute multiple SQL
 * commands simultaneously.
 * Written By Himansu Rathi 12/CS/06
 * */
import java.sql.*;
//Import necessary packages

public class executeSQL {
	   // JDBC driver name and database URL
	   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
	   static final String DB_URL = "jdbc:mysql://localhost:3306/testDb";

	   //  Database credentials
	   static final String USER = "username";
	   static final String PASS = "password";
   public static void main(String[] args) throws Exception{

	   Connection connection = null; 
	   Statement statement = null;
	   ResultSet result;
	   ResultSetMetaData metaData;
	   int numberColumns=2,columnCounter=1;
	   
	   //Declaration of requisite variables
	   try{
		   	//STEP 2: Register JDBC driver
		   	Class.forName(JDBC_DRIVER);//Checking whether JDBC driver is present
		   	System.out.println("JDBC Driver found");
	   	  }
      catch(ClassNotFoundException e) {
    	  	System.out.println("JDBC Driver not found "+ e);
      	  }
	   try{
	   		//STEP 3: Open a connection
	   		System.out.println("Connecting to database...");
	   		connection = DriverManager.getConnection(DB_URL, USER, PASS);
     		//Connecting to the database
	   		statement = connection.createStatement();
	   		
	   		connection.setAutoCommit(false);
	   		String insertEmp1 = "INSERT INTO employee (id,name) VALUES (2,'Jimmy Wales')";
	   		String insertEmp2 = "INSERT INTO employee (id,name) VALUES (3,'Aaron Swartz')";
	   		
	   		statement.addBatch(insertEmp1);
	   		statement.addBatch(insertEmp2);

	   		statement.executeBatch();
	   		connection.commit();
	   		
	   		System.out.println("Batch executed");
	   		result = statement.executeQuery("select * from employee");
	   		while(result.next()) // The next() method is used to successively step through the rows of the tabular results.
	   			{
	   				columnCounter=1;
	   				//Printing each row of the database
	   				while(columnCounter <= numberColumns)
	   				{
	   					System.out.print(result.getString(columnCounter)+" ");
	   					columnCounter++;
	   				}
	   				System.out.println();
	  			}
	    }
	   catch(SQLException e){
   	  	System.out.println("SQL exception occured Duplicate Rows!!");
   	  	//SQL Excepton
     	  }
   } 
}