//Santiago Flores
//Lab4 Link List

package Lab4;

public class IntNode {
	
	private int data;
	private IntNode link;
	
	public IntNode() {
		data = 0;
		link = null;
	}// of constructor
	
	public IntNode(int _data, IntNode _node) {
		data = _data;
		link = _node;
	}// of argument constructor
	
	//Get and set methods
	public int getData() {
		return data;
	}// of getData
	public IntNode getLink() {
		return link;
	}// of getLink
	public void setData(int d) {
		data = d;
	}// of setData
	public void setLink(IntNode l) {
		link = l;
	}// of setLink
	
	public String toString() {
		IntNode cursor = link;
		
		System.out.print(cursor.getData());
		cursor = cursor.link;
		
		while(cursor != null) {
			System.out.print("-> " + cursor.getData());
			cursor = cursor.link;
		}// of while
		System.out.println();
		return "";
		
	}// of to string
	
	public void addNodeAfterThis(int newdata) {
		link = new IntNode(newdata,link);
	}// of addNodeAfterThis
	
	public void removeNodeAfterThis() {
		link = link.link;
	}// of removeNodeAfterThis
	
	public static int listLength(IntNode head) {
		IntNode cursor = head;
		int count = 0;
		
		while(cursor != null) {
			count++;
			cursor = cursor.link;
		}// of while
		return count-1; //subtract one for the head being counted
	}// of listLength
	
	public static boolean search(IntNode head, int data) {
		IntNode cursor = head;
		while(cursor != null) {
			if(cursor.getData() == data) {
				return true;
			}//of if
			cursor = cursor.link;
		}// of while
		return false;
	}// of search
	
	
	public static void main(String[] args) {
		IntNode head = new IntNode();
		IntNode test = new IntNode(93, null);
		
		head.addNodeAfterThis(5);
		head.addNodeAfterThis(83);
		head.addNodeAfterThis(21);
		head.toString();           //prints the list 21->83->5
		
		System.out.println(listLength(head));          //return 3

		
		head.removeNodeAfterThis();// removes 21 and only prints 83 and 5
		head.toString();
		
		System.out.println(listLength(head));          //return 2 after removing
		
		System.out.println(search(head, 83));          //return true
		System.out.println(search(head, 29));          //return false
		
		System.out.println();
		
		System.out.println(test.getData());         //inital value 93
		System.out.println(test.getLink());         //inital set to null
		test.setData(3);
		test.setLink(head);
		System.out.println(test.getData());         //set to 3
		System.out.println(test.getLink());         //set to IntNode head
		
	}// of main

}// of class
