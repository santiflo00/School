/* 	FILE: task2.java
	Lab3 task2
   	This code finds the sequence to one instance of cups to another instance if there exist one
	Using a graph structure and DFS algorithm. The graph is created by the object Node that holds the values in an array
   	10/19/20
*/

import java.util.*;

class task2 {
	//Create statck that will hold the nodes of the graph for DFS 			
	static Stack<Node> stack = new Stack<>();
	static int[] maxSize = new int[]{10,7,4}; //max amount the cup can hold
    static HashSet<Node> seen = new HashSet<>(); //holds nodes that have been seen(cannot hold duplicates)
  
	public static void main(String[] args) {
		Pouring(0,7,4,2,7,2);  //Answer found
		Pouring(10,0,4,2,7,2);
		Pouring(8,6,3,7,6,4); //Answer found
		Pouring(1,7,4,3,6,2);
		Pouring(2,7,4,3,6,2);
		Pouring(6,3,3,3,6,3);
	}
	
	static void Pouring(int A,int B, int C, int A1, int B1, int C1) {
		Node init = new Node(new int[]{A,B,C});
    	seen.add(init);
		stack.push(init);
		boolean answer = false;

		while(!stack.isEmpty()) {
			Node currNode = stack.pop();
      		System.out.print("("+currNode.getCupAt(0)+","+currNode.getCupAt(1)+","+currNode.getCupAt(2)+")");
			
			if(currNode.getCupAt(0) == A1 && currNode.getCupAt(1) == B1 && currNode.getCupAt(2) == C1) {
				System.out.println("\nAnswer found");
				answer = true;
				break;		
			}
			//Look at every possible node that the current node has connections to by finding the 6 different possible iterations
			//The code will pour out the water in cup at i into cup j if it contains water
			for(int i = 0; i < currNode.getCups().length; i++) 
				for(int j = 0; j < currNode.getCups().length; j++) {
					if(i != j) {
						int cupI = currNode.getCupAt(i);
						int cupJ = currNode.getCupAt(j);
						int pourOut = maxSize[j]-cupJ;
						int pourIn;
						
						if(cupI < pourOut) pourIn = cupI;
						else pourIn = pourOut;
						
						if(cupI != 0) {
							int[] newCup = Arrays.copyOf(currNode.getCups(), currNode.getCups().length);
							newCup[i] = cupI-pourIn;
							newCup[j] = newCup[j]+pourIn;
							Node newNode = new Node(newCup); 
							if(!seen.contains(newNode)) { //if this node has not been seen push it and mark it as seen
                				seen.add(newNode);
								stack.push(newNode);
							}
						}
					}
				}//end j for
			//end i for	
		}//end while
    System.out.println();
		if(!answer)
			System.out.println("No sequence from ("+A+","+B+","+C+") to ("+A1+","+B1+","+C1+")\n");
	}//end pouring

//class to hold 3 values of the cups
	static class Node {
		private int[] cups; //hold the amount in the cups
		//boolean seen; //tell if this node has been looked at already
	
		public Node(int[] cups) {
			this.cups = cups;
			//seen = false;
		}

		public int[] getCups() {
			return cups;
		}
    	public int getCupAt(int i) {
      		if(i < 3)
        	return cups[i];
      	else
        	System.out.println("Error bad index");
        return -1;
    	}
    	//HashSet must override equals
    	@Override
    	public boolean equals(Object other){
      		return Arrays.equals(cups,((Node)other).getCups());
    	}

    	@Override
    	public int hashCode(){
      		return Arrays.hashCode(cups);
    	}
	}// end node
}//end class
