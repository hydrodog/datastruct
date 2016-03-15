#include <iostream>
using namespace std;

class RBTree {
private:
	enum class Color {RED, BLACK};
	class Node {
	public:
		Color c;
		Node* parent;
		Node* left;
		Node* right;
		int val;
		Node(int v, Node* parent, Node* left, Node* right) :
			c(RED), val(v), parent(parent), left(left), right(right) {}
		Node* grandparent() const {
			if (parent != nullptr)
				return parent->parent;
			return nullptr;
		}
		Node* uncle() const {
			Node* g = grandparent();
			if (g->left == parent)
				return g->right;
			else
				return g->left;
		}	
	};
	Node* root;
	void insertUnbalanced(int v) {
		Node* p = root;
		while (true) {
			if (p->val > v) { // go left!
				if (p->left == nullptr) {
					p = new Node(v, p, nullptr, nullptr);
					break;
				}
				p = p->left;
			} else {
				if (p->right == nullptr) {
					p = new Node(v, p, nullptr, nullptr);
					break;
				}
				p=p->right;
			}
		}
		insert1(p);
	}
	void insert1(Node* n) {
		if (n->parent == null)
			n->c = Color::BLACK;
		else if ((n->parent->c == Color::BLACK))
			return; // Tree is still valid
		else {
			Node *u = n->uncle(); 
			if (u != nullptr) && (u->c == Color::RED) {
					n->parent->c = Color::BLACK;
					u->c = Color::BLACK;
					Node* g = n->grandparent();
					g->c = Color::RED;
					insert1(g);
				} else {
				Node *g = n->grandparent();
				if ((n == n->parent->right) && (n->parent == g->left)) {
					rotate_left(n->parent);
					n = n->left;
				} else if ((n == n->parent->left) && (n->parent == g->right)) {
					rotate_right(n->parent);
					n = n->right; 
				}

				// TODO: Add case 5
			}
		}
	}
public:
	RBTree() : root(nullptr) { }
  void insert(int v) {
		insertUnbalanced(v);
	}
};
