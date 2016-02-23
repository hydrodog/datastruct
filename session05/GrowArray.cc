#include <iostream>
using namespace std;

class GrowArray {
private:
	int* p;
	int size;
	int used;
	// this should double the size of your list
	void grow() {

	}
public:
	GrowArray() : p(new int[1]), size(1), used(0) {
	}
	GrowArray(int capacity) : p(new int[capacity]), size(capacity), used(0) {
	}
	~GrowArray() {
		delete [] p;
	}
	void addStart(int v) { // O(   )
	}
	
 	void addEnd(int v) {  //O(    )
		if (used == size)
			grow();
		// O(1)
	}
	int getCapacity() const {
    return size;		
	}

	int getUsed() const {
		return used;
	}
	int get(int i) const { //O(1)
		if (i < 0 || i >= used)
			throw "Die!";
		return p[i];
	}
  void set(int i, int v) { // O(1)
		if (i < 0 || i >= used)
			throw "Die!";
		p[i] = v;
	}
	
};

int main() {
	BadGrowArray a;
	for (int i = 0; i < 1000000; i++)
		a.add(i);
}



	

	
	
