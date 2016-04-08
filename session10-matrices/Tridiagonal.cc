#include <iostream>
#include <cmath>
using namespace std;

class TriDiagonal {
private:
	double* m;
	int n;
public:
	TriDiagonal(int n) : n(n) {
		m = new double[3*n];
		for (int i = 0; i < 3*n; i++)
			m[i] = 0;
	}
	~TriDiagonal() {
		delete [] m;
	}
	TriDiagonal(const TriDiagonal& orig);
	TriDiagonal& operator =(const TriDiagonal& orig);

 	double operator() (int i, int j) const {
		if (abs(i-j) > 1)
			return 0;
		//		return m[3*i + j-i + 1];
		//		return m[2*i + j + 1];
		return m[2*i + j];
	}
 	double& operator() (int i, int j) {
		if (abs(i-j) > 1)
			return 0;
		return m[2*i + j];
	}
	
	
};

int main() {
  const	TriDiagonal m1(5,4);
	cout << m1(3,3);
	TriDiagonal m2(4,4);
	m2(3,3) = 5.2;
}

	
