
public class LinkedList2 {
	static class Node { //  LinkedList.Node
		int val;
		Node next;
		public Node(int v, int Node next) {
			val = v; this.next = next; 
		}
	}
	private Node head;

	public LinkedList() {
		head = null;
	}
	public void addStart(int v) {
 		head = new Node(v, head);
	}

	public void addEnd(int v) {
		if (head == null) {
			head = new Node(v, null);
			return;
		}
		Node p;
    for (p = head; p.next != null; p = p.next)
			;
		p.next = new Node(v, null);
	}

	int get(int pos)  {
    Node p = head;
		for (int i = 1; i < pos; i++) {
			p = p.next;
		}
		return p.val;
	}

	int size() {
		int i = 0;
		for (Node p = head;  p != null; p = p.next) {
			i++;
		}
		return i;
	}

	public static void main(String[] a) {
		LinkedList list1 = new LinkedList();
		for (int i = 0; i < 100; i++)
			list1.addEnd(i);
		for (int i = 0; i < list1.size(); i++)
			System.out.print(list1.get(i));
	}
}
