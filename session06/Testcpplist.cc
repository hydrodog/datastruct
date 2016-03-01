#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
	list<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
		a.push_front(i);
	}

	for (list<int>::iterator i = a.begin(); i != a.end(); ++i)
		cout << *i << ' ';

	//C++11
	for (auto x : a)
		cout << x << ' ';

	for (list<int>::reverse_iterator i = a.rbegin(); i != a.rend(); ++i)
		cout << *i << ' ';

	
}
