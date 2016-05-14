import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class RemoveCollection {

	static Scanner scan=new Scanner(System.in);
	public static void main(String[] args)
	{
		int ch;
		TreeSet<Integer> Set=new TreeSet<Integer>();
		displayMenu();
		do{
			System.out.println("\nEnter a choice");
			ch=scan.nextInt();
			switch(ch)
			{
			case 0:	Set=getinput("Enter a number");
					break;
			case 1: addElement(Set);
					break;
			case 2: removeElement(Set);
					break;
			case 3: deleteSet(Set);
					break;
			case 4: displayCollections(Set);
					break;
			case 5: SizeSet(Set);
					break;
			case 6: displayMenu();
					break;
			case 7: System.exit(0);
					break;
			default: System.out.println("The choice entered is incorrect");
					break;
			}
		}while(ch!=7);
	}
	public static void displayMenu()
	{
		System.out.println("Press 0 to create a TreeSet");
		System.out.println("Press 1 to add element in a TreeSet");
		System.out.println("Press 2 to remove an element in TreeSet");
		System.out.println("Press 3 to delete a TreeSet");
		System.out.println("Press 4 to display a TreeSet");
		System.out.println("Press 5 to find size of TreeSet");
		System.out.println("Press 6 to display options");
		System.out.println("Press 7 to exit the program");
		System.out.println();
	}
	public static void removeElement(TreeSet<Integer> Collect)
	{
		System.out.println("Enter a number to be removed\n");
		int key=scan.nextInt();
		if(Collect.contains(key)==true)
			Collect.remove(key);
		else
			System.out.println("The Required Element "+key+" is not present in the Set");
	}
	public static void addElement(TreeSet<Integer> Collect)
	{
		System.out.println("Enter a number to be inserted\n");
		int key=scan.nextInt();
		if(Collect.contains(key)==false)
			Collect.add(key);
	}
	public static void SizeSet(TreeSet<Integer> Collect)
	{
		System.out.println("The number of elements in Set is "+Collect.size());
	}
	public static void displayCollections(TreeSet<Integer> Collect)
	{
		System.out.println("\nThe Elements in Collector are");
		Iterator<Integer> itr;
		itr=Collect.iterator();
		while(itr.hasNext())
		{
			System.out.println(itr.next());
		}
	}
	public static void deleteSet(TreeSet<Integer> Collect)
	{
		System.out.println("Deleting all elements in TreeSet\n");
		Collect.clear();
	}
	public static TreeSet<Integer> getinput(String display)
	{
		char ch='y';
		TreeSet<Integer> set=new TreeSet<Integer>();
		while(ch=='y'|| ch=='Y')
		{
			System.out.println(display);
			try{
				 set.add(scan.nextInt());
				 System.out.println("Do you want to continue?(y/n)");
				 ch=scan.next().charAt(0);	
			}
			catch (Exception e) {
				System.err.println("An Exception was caught :"+ e.getMessage());
				System.exit(0);
			}
		}
		System.out.println("Creating a TreeSet.....\n");
		return set;
	}
}