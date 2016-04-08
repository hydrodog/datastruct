class Trie {
private:
	class Node {
		Node* child[26]
	};
	Node* root;
public:
	Trie() {
		root = new Node();
	}
	void add(string word) {}
	bool contains(string word) {
		Node* p = root;
		for (int i = 0; i < word.length(); i++) {
			p = p->child[word[i] - 'a' ];
			if (p == nullptr)
				return false;
		}
		return p->isWord;
	}
	bool startWith(string word);
}
