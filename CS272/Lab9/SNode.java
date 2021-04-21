package lab9;

public class SNode<E> {
	SNode<E> link;
	E data;
	
	public SNode() {
		link = null;
		data = null;
	}
	
	public SNode(SNode<E> node, E d) {
		link = node;
		data = d;
	}
	
	public SNode(E data) {
		link = null;
		this.data = data;
	}//constructor
	
	public E getData() {
		return data;
	}
	public void setData(E data) {
		this.data = data;
	}
	public SNode<E> getLink() {
		return link;
	}
	public void setLink(SNode<E> link) {
		this.link = link;
	}
	
	
}//class
