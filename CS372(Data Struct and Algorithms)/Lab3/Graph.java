import java.io.*;
import java.util.*;


class Graph {

	private int num;//number of vertices
	private LinkedList<Character> graph[];
	
	//Constructor
	@SuppressWarnings("unchecked")
	Graph(int v) { 
		num = v;
		graph = new LinkedList[v];//allocate each linked list before using it
		for(int i = 0; i < v; i++)
			graph[i] = new LinkedList();
	}

	void addEdge(char v1, char v2) {
		//Since its an undirected graph each edge connects both nodes
		int i = v1 - 65;//subtract ascii value to get index of node
		int j = v2 - 65;
		graph[i].add(v2);
		graph[j].add(v1);
	}
	void DFS(int v) {
		Stack<Character> stack = new Stack<>();
		char startN = (char)(v+65);
		System.out.println("DFS starting from "+ startN);
		boolean[] visit = new boolean[num];
		DFSUtil(v, visit, stack); 
		System.out.println();
	}
	void DFSUtil(int v, boolean[] visit, Stack<Character> st) {
		char node = (char)(v+65);

		st.push(node);
		int pre = st.search(node);		
		System.out.print(node+" "+pre+" ");

		visit[v] = true;
		Iterator<Character> i = graph[v].listIterator();
		while(i.hasNext()) {
			int n = i.next() - 65;
			if(!visit[n])
				DFSUtil(n,visit,st);
		int post = st.search(node);
		st.pop();
		System.out.println(post);	
		}//end while
	}

	public static void main(String args[]) {
		//The graph has 9 nodes with 10 edges
		Graph g = new Graph(9); 
		g.addEdge('A','B');
		g.addEdge('B','C');
		g.addEdge('A','E');
		g.addEdge('B','E');
		g.addEdge('C','F');
		g.addEdge('E','F');
		g.addEdge('F','I');
		g.addEdge('D','H');
		g.addEdge('D','G');
		g.addEdge('G','H');

		g.DFS(0);		
	}


}
