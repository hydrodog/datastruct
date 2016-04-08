#include <iostream>
#include <algorithm>
using namespace std;

vector<int> stack;

void doit(char s[]) {
	cout << s << '\n';
}

void permute(char s[]) {
	while (stack.size() > 0) {
		int N = stack.pop_back();
		cout << "permute " << N << '\n';
		if (N == 0) {
			doit(s);
		} else {
			for (int c = 0; c <= N; c++) {
				swap(s[c], s[N]);
				stack.push(N-1); // control must go to while loop...
				// how to do this iteratively???
				swap(s[c], s[N]);
			}
		}
	}
}

int main() {
	char s[] = "abc";
	stack.push(2);
	permute(s);

}
