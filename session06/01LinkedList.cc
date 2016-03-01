#include <iostream>
#include <string>
#include "TemplatedLinkedList.hh"
using namespace std;

int main() {
	LinkedList<int> list;
	for (int i = 0; i < 9; i++)
		list.add(i);
 	for (LinkedList<int>::Iterator i = list; i.notEnd(); ++i) {
    cout << i.val();
	}
 	for (LinkedList<int>::Iterator i = list.end(); i.notEnd(); --i) {
    cout << i.val();
	}

	LinkedList<string> list2;
	for (int i = 0; i < 9; i++)
		list2.add("hello");
 	for (LinkedList<string>::Iterator i = list2; i.notEnd(); ++i) {
    cout << i.val();
	}
 	for (LinkedList<string>::Iterator i = list2.end(); i.notEnd(); --i) {
    cout << i.val();
	}



}
