#include <iostream>
#include <string>
#include "TemplatedLinkedListFasterDestructor.hh"
using namespace std;

int main() {
	LinkedList<int> list;
	for (int i = 0; i < 9; i++)
		list.add(i);
  LinkedList<int> list2 = list;  // list = 8 7 6 5 4 3 2 1 0
	// list2 = 8 7 6 5 4 3 2 1 0
	//equivalent in java
	// LinkedList<Integer> list2 = list.clone();


}
