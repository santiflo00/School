/**
 * @author Santiago Flores
 * 
 */

package cs272;

public class IntNode {
	
	private int data;
	private IntNode link;
	
	
	/**
	 * constructor IntNode
	 */
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
		
		while(cursor != null) {
			System.out.print(cursor.getData() + "-> ");
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
	
	//IntNode Advanced functions
	public static int listEvenNumbers(IntNode head) {
		if(head == null) {return 0;}
		IntNode cursor = head.link;
		int count = 0;
		while(cursor != null) {
			if(cursor.getData() %2 == 0) {  
				count++;
			}// of if 
			cursor = cursor.link;
		}// of while
		return count;
	}// of listEvenNumbers
	
	public void addToEnd(int newdata) {
		IntNode cursor = link;
		IntNode pc = link.link;
		while(pc != null) {
			cursor = cursor.link;
			pc = pc.link;
		}//of while
		cursor.addNodeAfterThis(newdata);
	}// of addToEnd
	
	public static int sumLast(IntNode head, int num) {
		if(head == null) {return 0;}
		if(num <= 0) {return 0;}
		int add = 0;
		IntNode cursor = head;
		
		while(cursor != null) {
			if(num > listLength(head)) {//when num is bigger than list add all elements
				add = add + cursor.getData();
			}// of if
			else if(listLength(cursor) <= num-1) {
				add = add + cursor.getData();
				//System.out.println(listLength(cursor));
			}// of else if
			cursor = cursor.link;
		}//of while
		return add;
	}// of sumLast
	
	public static IntNode copyOdd(IntNode head) {
		if(head == null) {return null;}
		IntNode cursor = head;
		IntNode copy = new IntNode();
		while(cursor != null) {
			if(cursor.getData() %2 == 1) {
				copy.addNodeAfterThis(cursor.getData());
				//System.out.println(cursor.getData());
			}// of if
			cursor = cursor.link;
		}// of while 
		return copy;
	}// of copyOdd
	
	
	//Need to test
	public static IntNode removeAll(IntNode head, int e) {
		if(head == null) {return null;}
		IntNode cursor = head;
		IntNode newhead = new IntNode();
		while(cursor != null) {
			if(cursor.getData() != e) {
				newhead.addNodeAfterThis(cursor.getData());
			}// of if
			cursor = cursor.link;
		}// of while
		return newhead;
	}// of removeAll
	
	public static IntNode reverse(IntNode head) {
		if(head == null) {return null;}
		IntNode cursor = head;
		IntNode previous = null;
		IntNode next = null;
		while(cursor != null) {
            next = cursor.link; 
            cursor.link = previous; 
            previous = cursor; 
            cursor = next; 
		}// of while
		head = previous;
		return head;
	}// of reverse
	
	public static boolean hasCycle(IntNode head) {
		if(head == null) {return false;}
		IntNode cursor = head;
		int count = 0;
		while(cursor != null) {
			if(count == listLength(head)+1) {   //if count goes over the length there is a cycle
				return true;
			}// of if
			count++;
			cursor = cursor.link;
		}// of while
		return false;
	}// of hasCycle
	

}// of class
