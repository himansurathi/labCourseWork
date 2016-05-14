/*
 * Write a program to solve the Producer 
 * and Consumer Problem  using thread
 * Written By Himansu Rathi (12/CS/06) and Vivek Verma(12/CS/04) on 4/02/2015
 * Modules:
 * get()-to consume buffer
 * put()-to produce buffer
 * */

public class ProducerConsumer {
	public static void main(String[] args) {
		CubbyHole c = new CubbyHole();// Create a object of CubbyHole
		Producer p1 = new Producer(c, 1);//Create an object of Producer Class
		Consumer c1 = new Consumer(c, 1);//Create an object of Consumer Class
		p1.start(); 
		c1.start();
		//Calling start() method of thread
	}
}
class CubbyHole {
	private int contents;// A buffer of a single elemnt
	private boolean available = false;//Avaibility of Buffer
	public synchronized int get() {
		//syncronized() is called for proper execution of threads
		while (available == false) {
			try {
				System.out.println("Empty Buffer!!! Wait for the producers to produce");
				wait();
				//wait() is called for consumers if the buffer is empty() 
			}
			catch (InterruptedException e) {}
		}
		available = false;
		//Consume the buffer
		notifyAll();
		//Notify all the producers to produce data
		return contents;
	}
	public synchronized void put(int value) {
		while (available == true) {
			try {
				wait();
				//wait() is called for producers if the buffer is full() 
			}
			catch (InterruptedException e) {} 
		}
		contents = value;
		//Produce a buffer
		available = true;
		notifyAll();
		//Notify all the consumers to consume data
	}
}

class Consumer extends Thread {
	private CubbyHole cubbyhole;//A data member of CubbyHole Class
	private int number;
	public Consumer(CubbyHole c, int number) {
		//Initialize data members
		cubbyhole = c;
		this.number = number;
	}
	//Consumer to consume buffer
	public void run() {
		int value = 0;
		for (int i = 0; i < 10; i++) {
			//Consume buffer
			value = cubbyhole.get();
			System.out.println("Consumer #" + this.number+ " got: " + value);
		}
	}
}

class Producer extends Thread {
	private CubbyHole cubbyhole;//A data member of CubbyHole Class
	private int number;
	public Producer(CubbyHole c, int number) {
		//Initialize data members
		cubbyhole = c;
		this.number = number;
	}
	//Producer to produce buffer
	public void run() {
		for (int i = 0; i < 10; i++) {
			//Produce buffer
			cubbyhole.put(i);
			System.out.println("Producer #" + this.number+ " put: " + i);
			try {
				System.out.println("Buffer is Full!!! Waiting for Consumers");
				sleep((int)(Math.random() * 100));
				//sleep call to wait until buffer empty 
			} catch (InterruptedException e) { 
				System.out.println("Error No Consumers!!!");
				System.exit(0);
			}
		}
	}
}

