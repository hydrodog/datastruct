public class RBTree {
	private static class Node {
		boolean red;
		Node left, right, parent;
		int val;
		public Node(int v, Node parent, Node left, Node right) {
			val = v;
			red = true;
			this.parent = parent;
			this.left = left;
			this.right = right;
		}
		public Node grandparent() {
			if (parent != null)
				return parent.parent;
			else
				return null;
		}

		Node uncle() {
			Node g = grandparent();
			if (g == null)
				return null; // No grandparent means no uncle
			return parent == g.left ? g.right : g.left;
		}
		public void insert() {
			if (parent != null)
				red = false;
			if (parent.red == false)
				return; /* Tree is still valid */
			else {
				Node u = uncle();
				Node g;
				if (u != null && u.red == true) {
					parent.red = false;
					u.red = true;
					g = grandparent();
					g.red = true;
					g.insert();
				} else {
					g = grandparent();
					if ((this == parent.right) && (parent == g.left)) {
						parent.rotateLeft();
						this = this.left; // ? Java won't like this!!!
					} else if ((this == parent.left) && (parent == g.right)) {
						parent.rotateRight();
						this = this.right; 
					}
					parent.red = false;
					g.red = true;
					if (this == parent.left)
						g.rotateRight();
					else
						g.rotateLeft();
				}
			}
		}
	}
	private Node root;
	public BinaryTree() { root = null; }

	public void add(int v) {
		if (root == null) {
			root = new Node(v, null, null, null);
			return;
		}
		Node p = root;
		while (true) {
			if (v > p.val) {
				if (p.right == null) {
					p.right = new Node(v, p, null, null);
					return;
				}
				p = p.right;
			} else {
				if (p.left == null) {
					p.left = new Node(v, p, null, null);
					return;
				}
				p = p.left;
			}
		}
	}


}
