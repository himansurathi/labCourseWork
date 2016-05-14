/*
 * Write a program to join contents of more than
 * one table and display it. Use inner join SQL 
 * command to combine data from two tables.
 * To display the contents of the table
 * getString() methods of resultSet is used.
 * Written By Himansu Rathi(12/CS/06) on 17/03/2015
 * */
import java.sql.*; //Import necessary packages
public class JoinContents {
	   // JDBC driver name and database URL
	   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
	   static final String DB_URL = "jdbc:mysql://localhost:3306/testDb"; 
	   //Database credentials
	   static final String USER = "username";
	   static final String PASS = "password";
	   public static void main(String[] args) throws Exception{     
		   Connection connection = null; 
		   Statement statement = null;
		   ResultSet result;
		   int numberColumns=3,columnCounter=1;
		   //Declaration of requisite variables
		   try{
				Class.forName(JDBC_DRIVER);//Checking whether JDBC driver is present
			   	System.out.println("JDBC Driver found");
		   	  }catch(ClassNotFoundException e) {
	    	  	System.out.println("JDBC Driver not found "+ e);
	      	  }
		   try{
		   		//STEP 3: Open a connection
		   		System.out.println("Connecting to database...");
		   		connection = DriverManager.getConnection(DB_URL, USER, PASS);
	      		//Connecting to the database
		   		statement = connection.createStatement();
		   		String query ="SELECT id,name,isbn from author inner join books on author.id = books.bookid";
		   		//Joining of two tables author and books
		   		result = statement.executeQuery(query);//Execute Query
		   		System.out.println("id  name   ISBN");
		   		while (result.next()) {
		   			columnCounter=1;
	    	  		//Printing each row of the database
		    	  	while(columnCounter <= numberColumns){
		    	  		System.out.print(result.getString(columnCounter)+" ");
		    	  		columnCounter++;
		    	  	}
		    	  	System.out.println();
		   		}
		   }catch(SQLException e){
		    	  	System.out.println("SQL exception occured " + e);
		    	  	//SQL Excepton
	      	  }
	   }
}
