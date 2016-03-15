#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, double> price;
	price["IBM"] = 139.70;
	price["BABA"] = 71.39;
	price["XOM"] = 82.88;
	price["AAPL"] = 101.649;
	price["GOOG"] = 700.92;

	for (map<string, double>::iterator i = price.begin();i != price.end(); ++i)
		cout << i->first << "==>" << i->second << '\n';
}
	
