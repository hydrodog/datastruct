public class GraphMatrix {
	private double[] weights;
	private int v;
	public GraphMatrix(int v) {
		this.v = v;
		weights = new double[v*v];
		for (int i = 0; i < v*v; i++)
			weights[i] = Double.POSITIVE_INFINITY;
	}

	public void addEdge(int from, int to, double w) {
		weights[from * v + to] = w;
	}

	public double getWeight(int from, int to) {
		return weights[from * v + to];		
	}
}
