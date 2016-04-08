#include <iostream>
using namespace std;

class Upper {
private:
	double* m;
	int n;
	int size;
public:
	Upper(int n) : n(n), size(n*(n+1)/2) {
		m = new double[size];
		for (int i = 0; i < size; i++)
			m[i] = 0;
	}
	~Upper() {
		delete [] m;
	}
	Matrix(const Matrix& orig);
	Matrix& operator =(const Matrix& orig);

 	double operator() (int i, int j) const {
		if (i > j)
			return 0;
		//sum(1..n) = n(n+1)/2
		// sum(i..n) = (sum(1..n) - sum(1..i-1)
		//		n*(n+1)/2 - i*(i-1)/2 + j
		return m[size-i*(i-1)/2+j];
	}
 	double& operator() (int i, int j) {
		if (i > j)
			return 0;
		return m[size-i*(i-1)/2+j];
	}
	
	
};

int main() {
  const	Matrix m1(5,4);
	cout << m1(3,3);
	Matrix m2(4,4);
	m2(3,3) = 5.2;
}

	
