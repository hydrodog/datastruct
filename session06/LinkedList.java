public class LinkedList {
	private static class Node { // LinkedList.Node
		private int val;
		Node next;
		Node prev;
		Node(int v, Node next, Node prev) {
			val = v; this.next = next; this.prev = prev;
		}
	}
	private Node head;

  public void addStart(int v) {
    head = new Node(v, head, null);
		if (head.next != null)
			head.next.prev = head;
	}

	public void addEnd(int v) {
		if (head == null) {
			head = new Node(v, null, null);
      return;
		}
		Node p = head;
		while (p.next != null) {
			p = p.next;
		}
    p.next = new Node(v, null, p);
	}
	public void add(int v) {
		addStart(v);
	}
	public void removeStart() {
		head = head.next;
		head.prev = null;
	}
	public boolean isEmpty() {
		return head == null;
	}
		
	public void removeEnd() {
		Node p = head;
		while (p.next != null) {
			p = p.next;
		}
		p.prev.next = null;
	}

	public int get(int i) {
		Node p = head;
		for (int j = 0; j < i; j++) {
			p = p.next;
		}
		return p.val;
	}
  public static class Iterator {
		private Node p;
		private Iterator(Node p) {
			this.p = p;
		}
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
			p = p.prev;
		}
		public int get() {
			return p.val;
		}
	}
	public Iterator end() {
		if (head == null)
			return new Iterator((Node)null);
		Node p;
		for (p = head; p.next != null; p = p.next)
			;
		return new Iterator(p);
	}

	public static void main(String[] args) {
		LinkedList a = new LinkedList();
		for (int i = 0; i < 10; i++)
			a.add(i);
    for (int i = 0; i < 10; i++)
			System.out.print(a.get(i));
		for (LinkedList.Iterator i = new LinkedList.Iterator(a) ; i.hasNext(); i.next())
			System.out.print(i.get() + " ");
		for (LinkedList.Iterator i = a.end() ; i.hasNext(); i.prev())
			System.out.print(i.get() + " ");
	}
}
