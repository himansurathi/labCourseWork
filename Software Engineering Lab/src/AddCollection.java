import java.util.*;
public class AddCollection {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CollectionArray();
		CollectionList();
		CollectionVector();
		CollectionStack();
		CollectionQueue();
		CollectionPriorityQueue();
		CollectionDeque();
	}
	public static void CollectionArray()
	{
		ArrayList<Integer> array = new ArrayList<Integer>();
		array.add(5);
		System.out.println("The Array contains "+array.size()+" elements which are:-"+array);
	}
	public static void CollectionList()
	{
		LinkedList<Integer> list=new LinkedList<Integer>();
		list.add(5);
		System.out.println("The Array contains "+list.size()+" elements which are:-"+list);
	}
	public static void CollectionStack()
	{
		Stack<Integer> stack=new Stack<Integer>();
		stack.add(5);
		System.out.println("The Array contains "+stack.size()+" elements which are:-"+stack);
	}
	public static void CollectionVector()
	{
		Vector<Integer> vector=new Vector<Integer>();
		vector.add(5);
		System.out.println("The Array contains "+vector.size()+" elements which are:-"+vector);
	}
	public static void CollectionQueue()
	{
		Queue<Integer> queue=new LinkedList<Integer>();
		queue.add(5);
		System.out.println("The Array contains "+queue.size()+" elements which are:-"+queue);
	}
	public static void CollectionPriorityQueue()
	{
		PriorityQueue<Integer> pqueue=new PriorityQueue<Integer>();
		pqueue.add(5);
		System.out.println("The Array contains "+pqueue.size()+" elements which are:-"+pqueue);
	}
	public static void CollectionDeque()
	{
		Deque<Integer> dequeue=new ArrayDeque<Integer>();
		dequeue.add(5);
		System.out.println("The Array contains "+dequeue.size()+" elements which are:-"+dequeue);
	}
	public static void CollectionHashSet()
	{
		HashSet<Integer> hashset=new HashSet<Integer>();
		hashset.add(5);
		System.out.println("The Array contains "+hashset.size()+" elements which are:-"+hashset);
	}
	public static void CollectionLinkedHashSet()
	{
		LinkedHashSet<Integer> linkedhashset=new LinkedHashSet<Integer>();
		linkedhashset.add(5);
		System.out.println("The Array contains "+linkedhashset.size()+" elements which are:-"+linkedhashset);
	}
}
