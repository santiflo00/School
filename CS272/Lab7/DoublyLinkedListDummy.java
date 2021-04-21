package cs272;

public class DoublyLinkedListDummy {
	
	 DIntNode head;
	 DIntNode tail;
	private int length = 0;
	
	public DIntNode getHead() {
		return head;
	}
	
	public DIntNode getTail() {
		return tail;
	}
	
	public void setHead(DIntNode node) {
		head = node;
	}
	
	public void setTail(DIntNode node) {
		tail = node;
	}
	
	public DoublyLinkedListDummy() {
		head = new DIntNode( null, null);
		tail = new DIntNode(head,null);
		head.setNext(tail);

	}
	
	public int getLength() {
		return length;
	}
	
	//----------------------------------------\\
	/**
	 * Time complexity O(8)
	 * @param element
	 */
	public void addEnd(int element) {
		DIntNode newNode = new DIntNode(element,null, tail);  // node being added
		DIntNode p = new DIntNode();
		p = tail.getPrev();                        // node that was previously before the tail
		
		p.setNext(newNode);                        //previous points no new node
		newNode.setPrev(p);                        //New node points back to last node
		newNode.setNext(tail);                     // newNode now points to tail
		tail.setPrev(newNode);                     //tail points back to new element
		
		length++;
		
	}// of addEnd
	
	/**
	 * Time complexity O(9)
	 */
	public void removeFromHead() {
		DIntNode rNode = new DIntNode(); 
		rNode = head.getNext();          //node being removed
		head.setNext(rNode.getNext());   //set head to point to node after first node
		DIntNode Node2 = rNode.getNext();
		Node2.setPrev(head);              //point second node to head
		
		length--;
	}
	/**
	 * Time complexity O(n)
	 */
	public String toString() {
		String list =  "";
		DIntNode cursor = new DIntNode();
		cursor = head.getNext();
		System.out.print(cursor.getData());
		while(cursor != tail) {
			cursor = cursor.getNext();
			System.out.print("<->" + cursor.getData());
		}
		System.out.println();
		cursor = tail.getPrev();
		System.out.print(cursor.getData());
		while(cursor != head) {
			cursor = cursor.getPrev();
			System.out.print("<->" + cursor.getData());
		}
		System.out.println();
		return list;
	}
	
	/**
	 * Time complexity o(n)
	 * @param e
	 * @return
	 */
	public int countOccurrence(int e) {
		DIntNode cursor = new DIntNode();
		cursor = head.getNext();
		int count = 0;
		while(cursor != tail) {
			if(cursor.getData() == e) {
				count++;
			}// of if
			cursor = cursor.getNext();
		}// of while
		return count;
	}// of countOccurrence

	/**
	 * Time complexity O(n)
	 * @param e
	 * @return
	 */
	public boolean removeAll(int e) {
		DIntNode cursor = new DIntNode();
		DIntNode cNext, cPrev;
		boolean removed = false;
		cursor = head.getNext();
		while(cursor != tail) {
			
			cNext = cursor.getNext();
			cPrev = cursor.getPrev();
			
			if(cursor.getData() == e) {
				
				cNext.setPrev(cPrev);
				cPrev.setNext(cNext);
				removed = true;
				length--;
				
			}// of if
			cursor = cursor.getNext();
		}// of while
		return removed;
	}
	
	/**
	 * Time complexity O(n^2)
	 * @param beginIdx
	 * @param endIdx
	 * @return
	 */
	public DoublyLinkedListDummy subList(int beginIdx, int endIdx) {
		
		if(beginIdx < 0 || beginIdx > endIdx || beginIdx > length) {throw new IllegalArgumentException("Beginning Index must be greater or equal to zero and less than end Index") ;}
		
		DoublyLinkedListDummy newList = new DoublyLinkedListDummy();
		DIntNode cursor = new DIntNode();
		cursor = head.getNext();
		int count = 0;
		
		while(cursor != tail) {
			if(count == beginIdx) {
				while(count != endIdx) {
					newList.tail.setPrev(cursor);
					cursor = cursor.getNext();
					count++;
				}// of while count
			}//of if
			cursor = cursor.getNext();
			count++;
		}// of while
		
		return newList;
	}// of subList
	/**
	 * Time complexity O(n)
	 */
	public void printStatistics() {
		
		DIntNode cursor = new DIntNode();
		cursor = head.getNext();
		
		System.out.println("Number Occurrence");
		while(cursor != tail) {
			System.out.println(cursor.getData()+ "          " + countOccurrence(cursor.getData()));
			cursor = cursor.getNext();
		}// of while
		
	}// of printStatistics
	
}// of class
