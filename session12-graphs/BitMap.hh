/**
	 00000000000000000000000000000000000000
   10000001000000000000000000000000000000

 */


class BitmapGraph {
private:
	uint64_t* edges;
	int V;
public:
	BitmapGraph(int V) : V(V) {
		// 4 * (5) / 2 = 10
		edges = new uint64_t[ (V* (V+1) / 2 + 63) / 64];
	}

	bool adjacent(int v1, int v2) const {
		int index = v1 < v2 ?
											v2 * (v2 + 1) / 2 + v1 :
			v1 * (v1 + 1) / 2 + v2;
    return edges[index / 64] & (1 << index % 64);
	}
