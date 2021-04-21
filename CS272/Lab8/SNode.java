package Lab8;

public class SNode<E> {
	private E data;
	private SNode<E> link;
	private int items;

	public SNode() {
		link = null;
		data = null;
		items = 0;
	}// of constructor
	
	public SNode(E d, SNode<E> l) {
		link = l;
		data = d;
	}
	
	public void setLink(SNode<E> l) {
		link = l;
	}// of setLink
	
	public void setData(E d) {
		data = d;
	}// of setData
	
	
	public SNode<E> getLink(){
		return link;
	}
	
	public E getData() {
		return data;
	}
	
	public int getItems() {
		return items;
	}
	
	public void addItem() {items++;}
	
	public void removeItem() {items--;}
	
}// of class
