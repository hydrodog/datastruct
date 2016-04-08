#include <iostream>
using namespace std;

class Matrix {
private:
	double* m;
	int rows, cols;
public:
	Matrix(int rows, int cols) : rows(rows), cols(cols) {
		m = new double[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			m[i] = 0;
	}
	~Matrix() {
		delete [] m;
	}
	Matrix(const Matrix& orig);
	Matrix& operator =(const Matrix& orig);

 	double operator() (int i, int j) const {
    return m[i * cols + j];
	}
 	double& operator() (int i, int j) {
    return m[i * cols + j];
	}
	
	
};

int main() {
  const	Matrix m1(5,4);
	cout << m1(3,3);
	Matrix m2(4,4);
	m2(3,3) = 5.2;
}

	
