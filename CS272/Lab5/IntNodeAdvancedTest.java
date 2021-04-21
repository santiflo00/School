package cs272;

public class IntNodeAdvancedTest {

	public static void main(String[] args) {
		IntNode head = new IntNode();
		IntNode test = new IntNode(93, null);
		
		//IntNode test
		head.addNodeAfterThis(5);
		head.addNodeAfterThis(83);
		head.addNodeAfterThis(21);
		head.toString();           //prints the list 21->83->5
		
		System.out.println(IntNode.listLength(head));          //return 3

		
		head.removeNodeAfterThis();// removes 21 and only prints 83 and 5
		head.toString();
		
		System.out.println(IntNode.listLength(head));          //return 2 after removing
		
		System.out.println(IntNode.search(head, 83));          //return true
		System.out.println(IntNode.search(head, 29));          //return false
		
		System.out.println();
		
		System.out.println(test.getData());         //inital value 93
		System.out.println(test.getLink());         //inital set to null
		test.setData(3);
		test.setLink(head);
		System.out.println(test.getData());         //set to 3
		System.out.println(test.getLink());         //set to IntNode head
		
		//IntNode Advanced test --------------------------------------------------------------
		IntNode test2 = new IntNode();
		IntNode test3 = new IntNode();
		IntNode test4 = new IntNode();
		
		//Test for listEvenNumber method
		head.addNodeAfterThis(18);
		head.toString();
		System.out.println(IntNode.listEvenNumbers(head));  //retruns 1. 18 is the only even number
		
		//Test for addToEnd method
		head.addToEnd(47);                                  //Add 47 to end of list
		head.toString();
		
		//Test for sumLast funtion
		System.out.println(IntNode.listLength(head));
		System.out.println(IntNode.sumLast(head, 2));     //Add last 2 values 5+47=52
		System.out.println(IntNode.sumLast(head, 7));     //Add all values 18+83+5+47 = 153
		
		//Test for copyOdd method
		test2.setLink(IntNode.copyOdd(head));             //test2 only holds the odd values from head
		test2.toString();                                 //list does not contain 18
		System.out.println();
		
		//Test for removeAll method
		test3.setLink(IntNode.removeAll(head, 5));       //Set test3 to head without 5
		test3.toString();                                //print- 18-> 83-> 47
		test3.setLink(IntNode.removeAll(test3, 83));     //remove 83 from test3
		test3.toString();                                //print- 18-> 47
		System.out.println();
		
		System.out.println("reverse test");
		head.toString();
		test4.setLink(IntNode.reverse(head));            //Set test4 to be reverse of IntNode head
		test4.toString();

		System.out.println(IntNode.hasCycle(test4));     //test4 has no loop returns false
		IntNode test5 = new IntNode(0, test4);
		test5.toString();
		System.out.println(IntNode.hasCycle(test5));
		
	}// of main

}// of class IntNodeAdvancedTest
