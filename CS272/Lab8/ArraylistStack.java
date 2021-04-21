package Lab8;
import java.util.ArrayList;

public class ArraylistStack<E> implements StackInterface<E> {
	private ArrayList<E> data;
	
	public ArraylistStack() {
		data = new ArrayList<E>();
	}//of constructor
	
	public void push(E e) {
		data.add(data.size(),e);
	}// of push
	
	public E pop() {
		E x;
		x = data.remove(data.size()-1);
		return x;
	}// of pop
	
	public E top() {
		return (data.get(data.size()-1));
	}// of top
	
	public int size() {
		return data.size();
	}// of size
	
	public boolean isEmpty() {
		return data.isEmpty();
	}// of isEmpty
	
}// of class
