public class BinaryTree {
	private static class Node {
		Node left, right, parent;
		int val;
		public Node(int v, Node parent, Node left, Node right) {
			val = v;
			this.parent = parent;
			this.left = left;
			this.right = right;
		}
	public void inorder() {
		if (left != null)
			left.inorder();
 		System.out.print(val + " ");
		if (right != null)
			right.inorder();
	}
	public void preorder() {
 		System.out.print(val + " ");
		if (left != null)
			left.inorder();
		if (right != null)
			right.inorder();
	}
	public void postorder() {
		if (left != null)
			left.inorder();
		if (right != null)
			right.inorder();
 		System.out.print(val + " ");
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
	public void inorder() {
		if (root != null)
			root.inorder();
	}
	public void preorder() {
		if (root != null)
			root.preorder();
	}

	public void postorder() {
		if (root != null)
			root.postorder();
	}

	public static void main(String[] args) {
		BinaryTree b = new BinaryTree();
		int[] vals = { 3, 5, 4, 2, 1};
		for (int i = 0; i < vals.length; i++)
			b.add(vals[i]);
    b.inorder(); System.out.println();
    b.preorder(); System.out.println();
    b.postorder(); System.out.println();
	}		
}
