/*
 * Write a program to demonstrate the uses of different 
 * types of Collection Classes and adds an element in 
 * those collections.
 * Written By Himansu Rathi(12/CS/06) and Vivek Verma(12/CS/04) on 4/02/2015
 * */
import java.util.*;
public class AddCollectionAssignment {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CollectionArray();
		CollectionList();
		CollectionVector();
		CollectionStack();
		CollectionQueue();
		CollectionHashSet();
	}
	public static void CollectionArray()
	{
		ArrayList<Integer> array = new ArrayList<Integer>();
		array.add(5);
		array.add(3);
		System.out.println("The ArrayList contains "+array.size()+" elements which are:-"+array);
	}
	public static void CollectionList()
	{
		LinkedList<Integer> list=new LinkedList<Integer>();
		list.add(5);
		System.out.println("The LinkedList contains "+list.size()+" elements which are:-"+list);
	}
	public static void CollectionStack()
	{
		Stack<Integer> stack=new Stack<Integer>();
		stack.push(5);
		stack.push(3);
		stack.push(4);
		System.out.print("The Stack contains "+stack.size()+" elements which are:- ");
		while(!stack.empty())
		System.out.print(stack.pop()+" ");
		System.out.println();
	}
	public static void CollectionVector()
	{
		Vector<Integer> vector=new Vector<Integer>();
		vector.add(5);
		System.out.print("The Vector contains "+vector.size()+" elements which are:- ");
		for(Integer itr:vector)
		System.out.print(itr+" ");
		System.out.println();
	
	}
	public static void CollectionQueue()
	{
		Queue<Integer> queue=new LinkedList<Integer>();
		queue.add(5);
		queue.add(3);
		queue.add(4);
		System.out.println("The Queue contains "+queue.size()+" elements which are:-"+queue);
	}
	public static void CollectionHashSet()
	{
		HashSet<Integer> hashset=new HashSet<Integer>();
		hashset.add(5);
		hashset.add(3);
		hashset.add(4);
		System.out.println("The HashSet contains "+hashset.size()+" elements which are:-"+hashset);
	}
}


