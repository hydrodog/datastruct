#include <iostream>
using namespace std;

class LinkedList {
private:
  class Node {  // name of this class is LinkedList::Node
	public:
		int val;
		Node* next;
	};
  Node* head;
public:
	LinkedList() : head(nullptr) {}
	void addStart(int v) { //O(1)
		Node* p = new Node();
		p->val = v;
		p->next = head;
		head = p;
	}

	void removeStart() { //O(1)
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
	void addEnd(int v) { //O(n)
		if (head == nullptr) {
			addStart(v);
			return;
		}
		Node* p;
		for (p = head; p->next != nullptr; p = p->next)
			;
		p->next = new Node();
		p->next->val = v;
		p->next->next = nullptr;
	}
	void removeEnd() {
		
	}
	int get(int i) { //O(n)
		Node*p = head;
		for (int j = 0; j < i; j++)
			p = p->next;
		return p->val;
	}
};

int main() {
	LinkedList a;
  for (int i = 0; i < 10; i++)
		a.addStart(i);
	for (int i = 0; i < 10; i++)
		cout << a.get(i) << ' ';
}
