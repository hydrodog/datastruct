#include <iostream>
using namespace std;

class Lower {
private:
	double* m;
	int n;
public:
	Lower(int n) : n(n) {
		int size = n*(n+1)/2;
		m = new double[size];
		for (int i = 0; i < size; i++)
			m[i] = 0;
	}
	~Lower() {
		delete [] m;
	}
	Lower(const Lower& orig);
	Lower& operator =(const Lower& orig);

 	double operator() (int i, int j) const {
		if (i < j)
			return 0;
		return m[i*(i+1)/2 + j];
	}
 	double& operator() (int i, int j) {
		if (i < j)
			return 0;
		return m[i*(i+1)/2 + j];
	}
	
	
};

int main() {
  const	Lower m1(5,4);
	cout << m1(3,3);
	Lower m2(4,4);
	m2(3,3) = 5.2;
}

	
