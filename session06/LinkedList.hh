class LinkedList {
private:
	class Node {
	public:
		int val;
		Node* next;
		Node* prev;
		Node(int v, Node* next, Node* prev)
			: val(v), next(next), prev(prev) {}
	};
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}
	void addStart(int v) {
    head = new Node(v, head, nullptr);
	}
	
	void addEnd(int v) {
		if (head == nullptr) {
			head = new Node(v, nullptr, nullptr);
			return;
		}
		Node* p;
    for (p = head; p->next != nullptr; p = p->next)
			;
    p->next = new Node(v, nullptr, p);		
	}
	void add(int v) { addStart(v); }
  void insert(int v, int pos) {
		Node* p = head;
		for (int i = 0; i < pos; i++)
			p = p->next;
		Node* temp = new Node(v, p->next, p);
		p->next = temp; // break the link with the node before us
		temp->next->prev = temp;
	}
};


int main() {
	LinkedList list;
	for (int i = 0; i < 9; i++)
		list.add(i);
