#ifndef LINKEDLIST_HH_
#define LINKEDLIST_HH_

template<typename T>
class LinkedList {
private:
	class Node {
	public:
		T val;
		Node* next;
		Node(const T& v, Node* next)
			: val(v), next(next) {}
	};
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}
	void addStart(const T& v) {
    head = new Node(v, head);
	}
	
	void addEnd(const T& v) {
		if (head == nullptr) {
			head = new Node(v, nullptr);
			return;
		}
		Node* p;
    for (p = head; p->next != nullptr; p = p->next)
			;
    p->next = new Node(v, nullptr);		
	}
	void add(const T&  v) { addStart(v); }
  void insert(const T& v, int pos) {
		Node* p = head;
		for (int i = 0; i < pos; i++)
			p = p->next;
		Node* temp2 = p->next;
		Node* temp = new Node(v, p->next);
		p->next = temp; // break the link with the node before us
		temp->next = temp2;
	}
	class Iterator {
	private:
		Node* head;
		Node* p;
	public:
		Iterator(Node* p) : p(p) {}
		Iterator(const LinkedList<T>& list) {
			p = list.head;
		}
		bool notEnd() const {
			return p != nullptr; 
		}
		void operator++() {
			p = p->next;
		}
		void operator--() {
		}
		T val() const {
			return p->val;
		}
	};
	Iterator end() const {
		if (head == null) {
			return Iterator(nullptr);
		}
		Node* p = head;
		for ( ; p->next != nullptr; p = p->next)
			;
    return Iterator(p);
	}

};

#endif
