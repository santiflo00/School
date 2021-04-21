package cs272;

public class DoublyLinkedListDummyTest {

	public static void main(String[] args) {
		
		DoublyLinkedListDummy test1 = new DoublyLinkedListDummy();
		
		test1.addEnd(12);
		test1.addEnd(28);
		test1.addEnd(12);
		test1.addEnd(34);
		test1.addEnd(28);
		test1.toString();
		
		System.out.println();
		
		test1.removeFromHead();  //removes first int (12)
		test1.toString();
		
		System.out.println(test1.countOccurrence(12)); //return 1
		System.out.println(test1.countOccurrence(28)); //return 2
		System.out.println(test1.countOccurrence(94)); //return 0
		
		System.out.println(test1.removeAll(28)); //return true
		System.out.println(test1.removeAll(2));  //return false
		test1.toString();             //list without both 28s
		
		
		test1.printStatistics();
		test1.addEnd(12);
		test1.printStatistics();

	}// of main

}// of class
