class MatrixGraph {
private:
	double * weight;
	int V;
public:
	MatrixGraph(int V) : V(V) {
		weight = new double[V*V];
	}
	~MatrixGraph() { delete [] weight; }

	MatrixGraph(const MatrixGraph& orig);
	MatrixGraph& operator =(const MatrixGraph& orig);
	double weight(int v1, int v2) const {
		return weight[v1 * V + v2];
	}


	
}
