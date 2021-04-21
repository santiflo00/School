package lab9;

public class ArrayQueue<E> implements QueueInterface<E> {
	private E[] data;
	private int front;
	private int rear;
	private int size;
	
	@SuppressWarnings("unchecked")
	public ArrayQueue() {
		data = (E[]) new Object[10];
		front = 0;
		rear = 0;
		size = 0;
	}//constructor
	
	public void enqueue(E e) {
		if(size == data.length) {
			@SuppressWarnings("unchecked")
			E[] bigger = (E[]) new Object[data.length*2];
			int j = 0;
			for(int i = front; i < data.length; i++) {
				bigger[j++] = data[i];
			}//for loop from front
			for(int i = 0; i < rear; i++) {
				bigger[j++] = data[i];
			}//for loop to rear
			//double array
			front = 0;
			rear = data.length;
			data = bigger;
		}// of if
		data[rear] = e;
		rear++;
		if(rear == data.length)rear = 0;
		size++;
	}// enqueue
	
	public E dequeue() {
		E ans = data[front];
		if(size > 0) {
			front++;
			if(front==data.length)front=0;
			size--;
		}
		else throw new IllegalArgumentException("Empty Queue");
		if(size==0) {front =0; rear = 0;}
		return ans;
	}// dequeue
	
	public E front() {
		if(size == 0) {
			throw new IllegalArgumentException("Empty Queue");
		}
		else {
		E ans = data[front];
		return ans;
		}
	}// front
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return (size==0);
	}
}// class ArrayQueue
