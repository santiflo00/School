package Lab8;

public class StackTest {

	public static void main(String[] args) {
		
		System.out.println("----------Test for Int Linked Stack----------");
		LinkStack<Integer> intNodeTest = new LinkStack<Integer>();
		System.out.println(intNodeTest.isEmpty()); //return true
		intNodeTest.push(4);
//		System.out.println(intNodeTest.top()); 
		intNodeTest.push(389);
//		System.out.println(intNodeTest.top()); 
		intNodeTest.push(94);
		intNodeTest.push(-12);
		intNodeTest.push(47784);
		System.out.println(intNodeTest.top()); 
		System.out.println(intNodeTest.size()); //return 5
		intNodeTest.pop();                      //remove 47784
		System.out.println(intNodeTest.top());  //top should be -12
		System.out.println(intNodeTest.size()); //size 4
		System.out.println(intNodeTest.isEmpty());// return false
		
		
		System.out.println("----------Test for String Linked Stack----------");
		LinkStack<String> stringNodeTest = new LinkStack<String>();
		System.out.println(stringNodeTest.isEmpty()); //return true
		stringNodeTest.push("test");
//		System.out.println(intNodeTest.top()); 
		stringNodeTest.push("test2");
//		System.out.println(intNodeTest.top()); 
		stringNodeTest.push("test3");
		stringNodeTest.push("test4");
		System.out.println(stringNodeTest.top()); 
		System.out.println(stringNodeTest.size()); //return 
		stringNodeTest.pop();                      //remove test4
		System.out.println(stringNodeTest.top());  //top should be test3
		System.out.println(stringNodeTest.size()); //size 3
		System.out.println(stringNodeTest.isEmpty());// return false
		
		System.out.println("----------Test for double Linked Stack----------");
		LinkStack<Double> doubleNodeTest = new LinkStack<Double>();
		System.out.println(doubleNodeTest.isEmpty()); //return true
		doubleNodeTest.push(4.592); 
		doubleNodeTest.push(237.478);
		doubleNodeTest.push(38.475);
		doubleNodeTest.push(2.2);
		System.out.println(doubleNodeTest.top()); 
		System.out.println(doubleNodeTest.size()); //return 
		doubleNodeTest.pop();                      //remove test4
		System.out.println(doubleNodeTest.top());  //top should be test3
		System.out.println(doubleNodeTest.size()); //size 3
		System.out.println(doubleNodeTest.isEmpty());// return false
		
		
		System.out.println("----------Test for int ArrayList stack----------");
		ArraylistStack<Integer> intArrayTest = new ArraylistStack<Integer>();
		System.out.println(intArrayTest.isEmpty()); //return true
		intArrayTest.push(465); 
		intArrayTest.push(-38); 
		intArrayTest.push(9);
		intArrayTest.push(-12903);
		intArrayTest.push(8);
		System.out.println(intArrayTest.top()); 
		System.out.println(intArrayTest.size());   //return 5
		intArrayTest.pop();                        //remove 4
		System.out.println(intArrayTest.top());    //top should be -12903
		System.out.println(intArrayTest.size());   //size 4
		System.out.println(intArrayTest.isEmpty());// return false
		
	}// of main

}// of class
