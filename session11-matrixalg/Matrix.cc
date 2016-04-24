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
	Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols) {
		m = new double[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			m[i] = orig.m[i];
	}
	Matrix& operator =(const Matrix& orig);

	double operator()(int i, int j) const {
		return m[i * cols + j];
	}
	double& operator()(int i, int j) {
		return m[i * cols + j];
	}
	Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw "BadSize";
		Matrix c(a.rows, a.cols); //O(n^2)
		for (int i = 0; i < a.rows; i++)  O(n^2)
			for (int j = 0; j < a.cols; j++)
				c(i,j) = a(i,j) + b(i,j);
	}

	Matrix operator *(const Matrix& a, const Matrix& b) {
		if (a.cols != b.rows)
			throw "BadSize";
		for (int k = 0; k < a.rows; k++) {
			for (int j = 0; j < b.cols; j++) {
				c(k,j) = 0;
				for (int i = 0; i < a.cols; i++)
					c(k,j) += a(j,i) * b(i,k);
			}
		}
		


	
