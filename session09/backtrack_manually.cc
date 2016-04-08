#include <iostream>
#include <algorithm>
using namespace std;

void doit(char s[]) {
	cout << s << '\n';
}

void permute(char s[], int N) {
	cout << "permute " << N << '\n';
	if (N == 0) {
		doit(s);
		return;
	}
	for (int c = 0; c <= N; c++) {
 		swap(s[c], s[N]);
		permute(s, N-1);
		swap(s[c], s[N]);
	}
}

int main() {
	char s[] = "abc";
	permute(s, 2);
	//	char s2[] = "wxyz";
	//	permute(s2, 3);

}
