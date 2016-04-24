class Graph {
private:
	class Edge {
	public:
		int v2;
		double w;
	};
	
	vector< vector<Edge> >    edges;

	double weight(int v1, int v2) const {
		vector<Edge>& edgeList = edges[v1];
		for (int i = 0; i < edgeList.size(); i++)
			if (edgeList[i].v2 == v2)
				return edgeList[i].w;
		return std::numeric_limits<double>::infinity();
	}


};
