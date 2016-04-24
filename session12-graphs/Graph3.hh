class MatrixGraph {
private:
	double * weight;
	int V;
public:
	MatrixGraph(int V) : V(V) {
		weight = new double[V*(V+1)/2];
	}
	~MatrixGraph() { delete [] weight; }

	MatrixGraph(const MatrixGraph& orig);
	MatrixGraph& operator =(const MatrixGraph& orig);
	double weight(int v1, int v2) const {
		if (v1 < v2)
			return weight[v2 * (v2 + 1) / 2 + v1];
		else
			return weight[v1 * (v1 + 1) / 2 + v2];
	}


	
}
