public class GraphSymmetricMatrix {
	private double[] weights;
	private int v;
	public GraphSymmetricMatrix(int v) {
		this.v = v;
		weights = new double[v*(v+1)/2];
		for (int i = 0; i < v*(v+1)/2; i++)
			weights[i] = Double.POSITIVE_INFINITY;
	}

	public void addEdge(int from, int to, double w) {
		if (from < to)
			weights[from * (from+1)/2 + to] = w;
		else
			weights[to*(to+1) /2 + from] = w;
	}

	public double getWeight(int from, int to) {
		return weights[from * v + to];		
	}
}
