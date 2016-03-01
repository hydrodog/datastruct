#ifndef LINKEDLIST_HH_
#define LINKEDLIST_HH_

template<typename T>
class LinkedList {
private:
	class Node {
	public:
		T val;
		Node* next;
		Node* prev;
		Node(const T& v, Node* next, Node* prev)
			: val(v), next(next), prev(prev) {}
		~Node() {
			delete next;
		}
	};
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}
	~LinkedList() {
		delete head; // O(n)  space complexity  O(n)

	}
	void addStart(const T& v) {
		if (head == nullptr) {
			head = new Node(v, head, nullptr);
			return;
		}
		head = new Node(v, head, nullptr);
		head->next->prev = head;
	}
	
	void addEnd(const T& v) {
		if (head == nullptr) {
			head = new Node(v, nullptr, nullptr);
			return;
		}
		Node* p;
    for (p = head; p->next != nullptr; p = p->next)
			;
    p->next = new Node(v, nullptr, p);		
	}
	void add(const T&  v) { addStart(v); }
  void insert(const T& v, int pos) {
		Node* p = head;
		for (int i = 0; i < pos; i++)
			p = p->next;
		Node* temp = new Node(v, p->next, p);
		p->next = temp; // break the link with the node before us
		temp->next->prev = temp;
	}
	class Iterator {
	private:
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
			p = p->prev;
		}
		T val() const {
			return p->val;
		}
	};
	Iterator end() const {
		if (head == nullptr) {
			return Iterator(nullptr);
		}
		Node* p = head;
		for ( ; p->next != nullptr; p = p->next)
			;
    return Iterator(p);
	}

};

#endif
