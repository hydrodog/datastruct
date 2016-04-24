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
	private ArrayList<Edge>[] edges;
	public GraphEdgeList2(int V) {
 		edges = new ArrayList<Edge>[V];
		for (int i = 0; i < V; i++)
			edges[i] = new ArrayList<Edge>();
	}
	public void addEdge(int from, int to, double w) {
		ArrayList<Edge> e = edges[from];
		for (int i = 0; i < e.size(); i++)
			if (e.get(i).to == to) {
				e.get(i).weight = w;
				return;
			}
		edges[from].add(new Edge(to, w));
	}
	public double getWeight(int from, int to) {
		ArrayList<Edge> e = edges[from];
		for (int i = 0; i < e.size(); i++)
			if (e.get(i).to == to)
				return e.get(i).weight;
		return Double.POSITIVE_INFINITY;
	}
	
	public static void main(String[]args) {
		GraphEdgeList2 g = new GraphEdgeList2(5);
		g.addEdge(3,4, 1.2);

		double w = g.getWeight(3, 4);
		System.out.println(w);
	}
		
}
