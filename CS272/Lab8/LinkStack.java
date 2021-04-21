package Lab8;

public class LinkStack<E> implements StackInterface<E> {
	SNode<E> top;
	int s = 0;
	
	public LinkStack() {
		top = null;
	}// of constructor
	
	public void push(E e) {
		top = new SNode<E>(e, top);
		s++;
	}// push
	
	public E pop() {
		if(top == null) {throw new IllegalArgumentException("List is empty");}
		E x = top.getData();
		top = top.getLink();
		s--;
		return x;
	}// of pop
	
	public E top() {
		if(top == null) {throw new IllegalArgumentException("List is empty"); }
		E x = top.getData();
		return x;
	}// of top
	
	public int size() {
		if(top == null) {return 0; }
		return s;
	}// of size
	
	public boolean isEmpty() {
		return (top == null);
	}// of isEmpty
	

}// of class
