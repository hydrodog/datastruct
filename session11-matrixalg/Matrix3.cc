class Matrix {
private:
	double * m;
	int rows, int cols;

public:
	Matrix(int rows, int cols) : rows(rows), cols(cols) {
		m = new double[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			m[i] = 0;
	}
	~Matrix() {
		delete [] m;
	}

	double operator ()(int i, int j) const {
		return m[i * cols + j];
	}

	double& operator ()(int i, int j) {
		return m[i * cols + j];
	}

	double dotProd(int j, int k) {
		double sum = 0;
		for (int i = 0; i < rows; i++, j += cols, k += cols)
			//			sum += (*this)(i,j) * (*this)(i,k);
			//				sum += (*this)(i,j) * (*this)(i,k);
			sum += m[j] * m[k];
		return sum;
	}
	
	void gramSchmidt() {
		double scale = 0;
		for (int j = 0; j < cols; j++) {
			int c = j;
			for (int i = 0; i < rows; i++, c += cols)
				scale += m[c] * m[c];
			c = 0;
			scale = 1/sqrt(scale);
			for (int i = 0; i < rows; i++, c += cols)
				m[c] *= scale;
      for (int k = j+1; k < cols; k++) {
				double mag = sqrt(dotProd(j,k));
				for (int i  = 0; i < rows; i++)
					m(i,k) = m(i,k) - mag * m(i,j);
			}
	}
