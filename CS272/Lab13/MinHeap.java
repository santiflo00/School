package lab13;
import java.util.ArrayList;

public class MinHeap {
	
	ArrayList<Integer> heap;
	
	public MinHeap() {heap = new ArrayList<Integer>();}
	
	private int leftChild(int i) {return 2*i + 1;}// get index of left child
	private int rightChild(int i) {return 2*i + 2;}//get index of right child
	private int parent(int i) {return ((i-1)/2);} //get index of parent

	public void add(int e) {
		if(heap.isEmpty()) {heap.add(0, e);return;}
		heap.add(heap.size(), e);
		int i = heap.size()-1;
		int p = parent(i);
		while(p != i && heap.get(i) < heap.get(p)) {
			swap(i, parent(i));
			i = parent(i);
		}
	}//add
	
	private void swap(int x, int y) {
		int temp;
		temp = heap.get(y);
		heap.set(y, heap.get(x));
		heap.set(x, temp);
	}//swap
	
	//remove top(smallest) element
	public int remove() {
		int ans;
		ans = heap.get(0);
		if(heap.isEmpty())throw new IllegalArgumentException("Empty heap");
		heap.set(0, heap.get(heap.size()-1));
		heap.remove(heap.size()-1);
		heapify(0);
		return ans;
	}//remove
	private void heapify(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int min = -1;

        // find the smallest element between a parent and its children
        if (left <= heap.size() - 1 && heap.get(left) < heap.get(i)) {
        	min = left;
        } 
        else min = i;
        if (right <= heap.size() - 1 && heap.get(right) < heap.get(min)) {
            min = right;
        }
        if (min != i) {
            swap(i, min);
            heapify(min);
        }
	}//heapify
	
	
	public int top() {
		if(heap.isEmpty())throw new IllegalArgumentException("Empty heap");
		return heap.get(0);
	}//top
	
	public String toString() {
		return heap.toString();
	}

	public static void main(String[] args) {
		MinHeap test1 = new MinHeap();
		MinHeap test2 = new MinHeap();
		test1.add(3);
		System.out.println(test1.toString()+"\n");
		test1.add(74);
		test1.add(1);
		System.out.println("Heap with Top: " + test1.top());//One becomes top since it is smallest value
		test1.add(4);
		System.out.println(test1.toString());
		System.out.println("remove top: " + test1.remove());
		System.out.println(test1.toString());//1 with left child 4 and right child 3 and 4 with left child 74
		test1.add(12);
		System.out.println(test1.toString());
		test1.remove();
		System.out.println("Top: " + test1.top());
		System.out.println(test1.toString());//3 is top with added 12 after 4
		test1.remove();
		System.out.println(test1.toString());
		test1.remove();
		System.out.println(test1.toString()+"\n");
		
		System.out.println("Test 2");
		test2.add(32);
		test2.add(48);
		test2.add(1);
		test2.add(95);
		test2.add(2389);
		test2.add(8239);
		System.out.println("Heap with top: "+test2.top()+" "+test2.toString());
		test2.remove();
		System.out.println("Heap with top: "+test2.top()+" "+test2.toString());
		test2.remove();
		System.out.println("Heap with top: "+test2.top()+" "+test2.toString());
		
	}//main

}//class
