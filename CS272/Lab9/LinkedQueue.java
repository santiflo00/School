package lab9;

public class LinkedQueue<E> implements QueueInterface<E> {
	private SNode<E> front;
	private SNode<E> rear;
	private int size;
	
	public LinkedQueue() {
		rear = null;
		front = null;
		size = 0;
	}//constructor
	
	public void enqueue(E e) {
		SNode<E> temp = new SNode<E>(e);
		temp = rear;
		rear = new SNode<E>();
		rear.data = e;
		rear.link = null;
		if(isEmpty())
			front = rear;
		else
			temp.link = rear;
		size++;
	}//enqueue
	
	public E dequeue() {
		if(front == null) throw new IllegalArgumentException("Queue is empty");
		SNode<E> temp = front;
		front = front.link;
		size--;
		return temp.getData();
	}//dequeue
	
	public E front() {
		return (front.getData());
	}// front
	
	public int size() {
		return size;
	}// of size
	
	public boolean isEmpty() {
		return (size==0);
	}
}// class
