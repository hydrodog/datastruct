#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix {
private:
	double* m;
	int rows, cols;
	Matrix(int rows, int cols, const char*) : rows(rows), cols(cols) {
		m = new double[rows*cols];
	}

public:
	Matrix(int rows, int cols) : rows(rows), cols(cols) {
		m = new double[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			m[i] = 0;
	}
	~Matrix() {
		delete [] m;
	}
	Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols) {
		m = new double[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			m[i] = orig.m[i];
	}
	Matrix& operator =(const Matrix& orig) {
		if (this != &orig) {
			delete [] m;
			m = new double[rows*cols];
			for (int i = 0; i < rows*cols; i++)
				m[i] = orig.m[i];
		}
		return *this;
	}

	double operator()(int i, int j) const {
		return m[i * cols + j];
	}
	double& operator()(int i, int j) {
		return m[i * cols + j];
	}
	friend Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw "BadSize";
		Matrix c(a.rows, a.cols, "noinit"); //O(n^2)
		for (int i = 0; i < a.rows*a.cols; i++)
			c.m[i] = a.m[i] + b.m[i];
		return c;
	}
	friend Matrix operator *(const Matrix& a, const Matrix& b) {
		if (a.cols != b.rows)
			throw "BadSize";
		Matrix c(a.rows,b.cols);
		for (int k = 0; k < a.rows; k++) {
			for (int j = 0; j < b.cols; j++) {
				double temp = 0;
				for (int i = 0; i < a.cols; i++)
					temp += a(k,i) * b(i,j);
				c(k,j) = temp;
			}
		}
		return c;
	}

	friend Matrix mult(const Matrix& a, const Matrix& b) {
		if (a.cols != b.rows)
			throw "BadSize";
		Matrix c(a.rows,b.cols);
		int d = 0;
		for (int k = 0; k < a.rows; k++) {
			for (int j = 0; j < b.cols; j++) {
				double temp = 0;
				int e = k * a.cols;
				int f = j;
				for (int i = 0; i < a.cols; i++, e++, f += b.cols)
					temp += a.m[e] * b.m[f];
				c.m[d++] = temp;
			}
		}
		return c;
	}

	Matrix transpose() const {
		Matrix t(cols, rows, "noinit");
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				t(j,i) = (*this)(i,j);
		return t;
	}

	Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols) {
		m = orig.m;
		orig.m = nullptr;
	}
	
	friend Matrix mult2(const Matrix& a, const Matrix& b) {
		if (a.cols != b.rows)
			throw "BadSize";
		Matrix t = b.transpose();
		Matrix c(a.rows,b.cols);
		int d = 0;
		for (int k = 0; k < a.rows; k++) {
			for (int j = 0; j < b.cols; j++) {
				double temp = 0;
				int e = k * a.cols;
				for (int i = 0; i < a.cols; i++, e++)
					temp += a.m[e] * t.m[e];
				c.m[d++] = temp;
			}
		}
		return c;
	}	

};

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	Matrix m1(n,n); // O(n^2)
	Matrix ans(n,n);// O(n^2)
	for (int i = 0; i < 100; i++) {
		//		ans = m1 * m1; // O(n^3)
		ans = mult(m1,m1); // O(n^3)
		//				ans = mult2(m1,m1); // O(n^3) NOT WORKING
	}
}
