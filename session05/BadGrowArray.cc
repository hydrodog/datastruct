#include <iostream>
#include <cstdint>
using namespace std;

class BadGrowArray {
private:
	int* p;
	int len;
public:
	BadGrowArray() : p(nullptr), len(0) {}
	~BadGrowArray() {
		delete [] p; // O(1)
	}
	void addEnd(int v) { // O(n)
		int *temp = p; // remember the old numbers
		p = new int[len+1]; //C++ = O(1),   Java = O(n)
    for (int i = 0; i < len; i++)
			p[i] = temp[i];
		p[len] = v;
		len++;
		delete[] temp;
	}
	void addStart(int v) { // O(n)
		int* temp = p;
		p = new int[len+1];
    for (int i = 0; i < len; i++)
			p[i+1] = temp[i];
		p[0] = v; // add the new element
		delete [] temp;
		len++;
	}

#if 0
	void addStart(int v) {
		int* temp = p; //O(1)
		p = new int[len+1]; // O(1) in java O(n)
		for (int i = 1; i <= len; i++) { //O(n)
			p[i] = temp[i-1];
		}
		p[0] = v;
		len++;
		delete [] temp;
	}
	void addEnd(int v) {
		int* temp = p; //O(1)
		p = new int[len+1]; // O(1) in java O(n)
		for (int i = 0; i < len; i++) { //O(n)
      p[i] = temp[i];
		}
		p[len] = v; //O(1)
		len++;
		delete [] temp;
	}
#endif
	int get(int i) {
		if (i < 0 || i >= len)
			throw "Exception";
		return p[i];
	}
};

int main() {
	BadGrowArray a;
	for (int i = 0; i < 1000000; i++) // O(n^2)
		a.addEnd(i); // 1 + 2 + 3 + 4 ... + n = O(n^2) 10^6^2 = 10^12

	for (int i = 0; i < 10; i++) // O(n)
		cout << a.get(i) << ' ';
}
