package lab9;

public class QueueTest {

	public static void main(String[] args) {
		
		System.out.println("-----------Array Queue Integer Test---------");
		ArrayQueue<Integer> aIntTest = new ArrayQueue<Integer>();
		System.out.println(aIntTest.isEmpty()); //True
		aIntTest.enqueue(3);
		System.out.println("Size of Queue: "+aIntTest.size());// size is 1
		System.out.println(aIntTest.front());
		aIntTest.enqueue(49);
		aIntTest.enqueue(-294);
		aIntTest.enqueue(2);                 //Queue <-3|49|-294|2<-
		System.out.println("Size of Queue: " +aIntTest.size()); // size is 4
		System.out.println(aIntTest.front()); //return 3
		aIntTest.dequeue();
		System.out.println("Size of Queue: "+aIntTest.size()); //size is now 3
		System.out.println(aIntTest.front());// return 49
		System.out.println(aIntTest.isEmpty()); //false
		aIntTest.enqueue(5739);
		aIntTest.enqueue(4);
		aIntTest.enqueue(94);
		aIntTest.enqueue(48);
		aIntTest.enqueue(584);
		aIntTest.enqueue(0);
		aIntTest.enqueue(48392);
		aIntTest.enqueue(32);
		System.out.println(aIntTest.front()); //test for when array goes over initial capacity return 49  still

		System.out.println("\n---------Array Queue Character Test-------------");
		ArrayQueue<Character> aCharTest = new ArrayQueue<Character>();
		aCharTest.enqueue('s');
		System.out.println(aCharTest.front());
		aCharTest.enqueue('a');
		aCharTest.enqueue('n');
		aCharTest.enqueue('t');
		aCharTest.enqueue('i');
		System.out.println("Front character: "+aCharTest.front()+" with size: "+ aCharTest.size());
		for(int i = 0; i < 5; i++) System.out.print(aCharTest.dequeue());
		
		System.out.println("\n-----------Linked Queue Double Test--------------");
		LinkedQueue<Double> lDoubleTest = new LinkedQueue<Double>();
		System.out.println(lDoubleTest.isEmpty());
		lDoubleTest.enqueue(23.4);
		System.out.println("Front element: "+lDoubleTest.front()+" with size: "+lDoubleTest.size());
		lDoubleTest.enqueue(7332.48);
		lDoubleTest.enqueue(81.234);
		lDoubleTest.enqueue(-0.3);
		System.out.println("Queue with size: "+lDoubleTest.size());
		lDoubleTest.dequeue();
		System.out.println("Front element: "+lDoubleTest.front()+ " with size: "+lDoubleTest.size());
		System.out.println(lDoubleTest.isEmpty());
		
		System.out.println("\n--------------Linked Queue String Test--------------");
		LinkedQueue<String> lStringTest = new LinkedQueue<String>();
		System.out.println(lStringTest.isEmpty());
		lStringTest.enqueue("test1");
		System.out.println("Front element: \""+lStringTest.front()+"\" with size: "+lStringTest.size());
		lStringTest.enqueue("test2");
		lStringTest.enqueue("test3");
		lStringTest.enqueue("test4");
		System.out.println("Queue size after added elements: "+lStringTest.size());
		lStringTest.dequeue();
		System.out.println("Front element: \""+lStringTest.front()+"\" with size: "+lStringTest.size());
		
	}// of main

}// of class
