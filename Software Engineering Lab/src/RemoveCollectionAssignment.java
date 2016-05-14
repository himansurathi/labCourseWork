/*
 * Write a program to demonstrate how to remove a 
 * certain element from  a collection with the help 
 * of collection.remove() method of collection class
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 4/02/2015
 * */

import java.util.Iterator;
import java.util.TreeSet;
//Import necessary packages

public class RemoveCollectionAssignment {
	public static void main(String[] args){
		TreeSet<Integer> Set=new TreeSet<Integer>();
		//Creating an empty TreeSet
		addElement(Set,5);
		addElement(Set,3);
		addElement(Set,4);
		addElement(Set,3);
		//Adding elements to TreeSet
		displayCollections(Set);
		//Displaying elements of TreeSet
		removeElement(Set,3);
		removeElement(Set,3);
		//Removing the elements of TreeSet
		displayCollections(Set);
	}
	//Removing Elements from Collection
	public static void removeElement(TreeSet<Integer> Collect,int key){
		if(Collect.contains(key)==true){
			Collect.remove(key);
			System.out.println("The Required Element "+key+" is deleted from the Set");		
		}
		else
			System.out.println("The Required Element "+key+" is not present in the Set");
		//Reporting error if element was absent
	}
	//Adding Element to Collection
	public static void addElement(TreeSet<Integer> Collect,int key){
		if(Collect.contains(key)==false){
				Collect.add(key);
				System.out.println("The Required Element "+key+" is added to the Set");
			}
		else
			System.out.println("The Required Element "+key+" is already present in the Set");
		//Reporting error for duplicate elements
	}
	//Displays the Elements of Collection
	public static void displayCollections(TreeSet<Integer> Collect){
		System.out.println("\nThe Elements in Collector are");
		Iterator<Integer> itr; // An Iterator for TreeSet
		itr=Collect.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		//Display Elements of TreeSet from beginning to End
		}
	}
}
