public class GraphEdgeList {
	/*
		{ {3, 6, 9},
		  {},
      {5, 9}
    }
	 */
	private static class Edge {
		int to;
		double weight;
		public Edge(int to, double w) { this.to = to; weight = w; }
	}
	private Edge[][] edges;
	//	private ArrayList<  ArrayList<Edge> >
	public GraphEdgeList(int V) {
		edges = new Edge[V][V]; // first null, stop looking!
	}
	public void addEdge(int from, int to, double w) {
		edges[from][to] = new Edge(to, w);
	}
	public double getWeight(int from, int to) {
		Edge e = edges[from][to];
		if (e == null)
			return Double.POSITIVE_INFINITY;
		return e.weight;
	}
	
	public static void main(String[]args) {
		GraphEdgeList g = new GraphEdgeList(5);
		g.addEdge(3,4, 1.2);

		double w = g.getWeight(3, 4);
		System.out.println(w);
	}
		
}
