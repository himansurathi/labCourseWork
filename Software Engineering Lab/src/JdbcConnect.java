/*
 * Write a program to execute query in JDBC. Assume 
 * databse name is testDb and it has table names 
 * employee which has two records.Use getconnection(),
 * createStatement() and executeQuery() methodsw to 
 * connect to a database and execute queries. 
 * Written By Himansu Rathi(12/CS/06) on 17/03/2015
 * */
import java.sql.*;
//Import necessary packages
public class JdbcConnect { 

	   // JDBC driver name and database URL
	   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
	   static final String DB_URL = "jdbc:mysql://localhost:3306/testDb";

	   //Database credentials

	   static final String USER = "username";
	   static final String PASS = "password";
	   public static void main(String[] args) {

	   Connection connection = null; 
	   Statement statement = null;
	   ResultSet result;
	   ResultSetMetaData metaData;
	   int numberColumns,columnCounter=1;//Declaration of requisite variables

	   try{ //STEP 2: Register JDBC driver
		   	Class.forName(JDBC_DRIVER);//Checking whether JDBC driver is present
		   	System.out.println("JDBC Driver found");
	   	  }catch(ClassNotFoundException e) {
    	  	System.out.println("JDBC Driver not found "+ e);
      	  }

	   try{		//STEP 3: Open a connection
		   		System.out.println("Connecting to database...");
		   		connection = DriverManager.getConnection(DB_URL, USER, PASS);//Connecting to the database
		   		int no_of_rows = 0;
	    	  	statement = connection.createStatement();//Create Statement
	    	  	result = statement.executeQuery("SELECT * FROM employee");//Execute Query 
	    	  	metaData=result.getMetaData(); //to form metadata result set 
	    	  	numberColumns=metaData.getColumnCount();
	    	  	while (result.next()){
	    	  		columnCounter=1;
	    	  		//Printing each row of the database
		    	  	while(columnCounter <= numberColumns)
		    	  	{
		    	  		System.out.print(result.getString(columnCounter)+" ");
		    	  		columnCounter++;
		    	  	}
		    	  	System.out.println();
		    	  	no_of_rows++;
	    	  	}
	    	  	if(no_of_rows!=2) //Check if number of rows is 2
	    	  		System.out.println("Error only 2 records should be present in database!!!");
	    	  	else
	      	  		System.out.println("There are "+ no_of_rows + " records in the table");  	  		
	   	  }catch(SQLException e){
    	  	System.out.println("SQL exception occured " + e);
    	  	//SQL Excepton
      	  }
   	 }
}
