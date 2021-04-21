import java.util.*;

class graph {
	int num;
	LinkedList<Integer> g[];

	graph(int n) {
		num = n;
		g = new LinkedList[n];
		for(int i=0; i<n; i++)
			g[i] = new LinkedList()
	}

	void addEdge(int v1, int v2) {
		g[v1].add(v2);
	}

}
