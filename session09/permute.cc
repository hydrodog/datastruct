#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int x[] = {1, 2, 3, 4};
	do {
		for (int i = 0; i < 4; i++)
			cout << x[i] << '\t';
		cout << '\n';
	} while (std::next_permutation(x, x+4));
}
