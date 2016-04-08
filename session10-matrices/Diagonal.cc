#include <iostream>
using namespace std;

class Diagonal {
private:
	double* m;
	int n;
public:
	Diagonal(int n) : n(n) {
		m = new double[n];
		for (int i = 0; i < n; i++)
			m[i] = 0;
	}
	~Diagonal() {
		delete [] m;
	}
	Diagonal(const Diagonal& orig);
	Diagonal& operator =(const Diagonal& orig);

 	double operator() (int i, int j) const {
		if (i != j)
			return 0;
		return m[i];
	}
 	double& operator() (int i, int j) {
		if (i != j)
			return 0;
		return m[i];
	}
	
	
};

int main() {
  const	Diagonal m1(5,4);
	cout << m1(3,3);
	Diagonal m2(4,4);
	m2(3,3) = 5.2;
}

	
