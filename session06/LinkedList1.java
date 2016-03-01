public class LinkedList {
	private static class Node { // LinkedList.Node
		private int val;
		Node next;
		Node(int v, Node next) {
			val = v; this.next = next;
		}
	}
	private Node head;

  public void addStart(int v) {
    head = new Node(v, head);
	}

	public void addEnd(int v) {
		if (head == null) {
			head = new Node(v, null);
      return;
		}
		Node p = head;
		while (p.next != null) {
			p = p.next;
		}
    p.next = new Node(v, null);
	}
	public void add(int v) {
		addStart(v);
	}
	public void removeStart() {
		head = head.next;
	}
	public boolean isEmpty() {
		return head == null;
	}
		
	public void removeEnd() {
		Node p = head;
		while (p.next.next != null) {
			p = p.next;
		}
		p.next = null;
	}

	public int get(int i) {
		Node p = head;
		for (int j = 0; j < i; j++) {
			p = p.next;
		}
		return p.val;
	}
  public static class Iterator {
		private Node head;
		private Node p;
		public Iterator(LinkedList list) {
			p = list.head;
		}
    public boolean hasNext() {
			return p != null;
		}
		public void next() {
			p = p.next;
		}
		public void prev() {
			Node q = head;
			while (q.next != p)
				q = q.next;
		  p = q;
		}
		public int get() {
			return p.val;
		}
	}

	public static void main(String[] args) {
		LinkedList a = new LinkedList();
		for (int i = 0; i < 10; i++)
			a.add(i);
    for (int i = 0; i < 10; i++)
			System.out.print(a.get(i));
		for (LinkedList.Iterator i = new LinkedList.Iterator(a) ; i.hasNext(); i.next())
			System.out.print(i.get() + " ");
	}
	for (LinkedList.Iterator i = a.end() ; i.hasNext(); i.prev())
			System.out.print(i.get() + " ");
		
}
