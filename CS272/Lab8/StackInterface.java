package Lab8;

public interface StackInterface<E> {
	public void push(E e);
	public E pop();
	public E top();
	public int size();
	public boolean isEmpty();
}// of stackInterface
