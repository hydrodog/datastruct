#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x*x - 7; }
typedef double (*FuncOneVar)(double x);

double bisection(FuncOneVar f, double a, double b, double eps) {
	double ya = f(a), yb = f(b);
	if (ya * yb >= 0) {
		cerr << "possibly no solution?\n";
		exit(-1);
	}
	// we now have two points one above, one below the x axis
	
	if (ya > yb) {
		swap(a, b);
	}
	// f(a) < 0 < f(b)
	double x;

	do {
		x = (a+b)/2;
		if (f(x) > 0)
			b = x;
		else if (f(x) < 0)
			a = x;
		else
			return x;
	} while ( abs(b - a) > eps);
	//	guess improves by a factor of 2 = 1 bit
}





	
	
}
