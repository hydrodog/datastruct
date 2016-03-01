public class Queue {
	private int[] data;
	private int head, tail;
	private void grow() {
		// left as optional work for the reader...
	}
	public Queue(int size) {
		data = new int[size];
		head = tail = 0;
	}
	void enqueue(int v) {
		data[head] = v;
		head = (head + 1) % data.length;
		if (head == tail) {
			grow();
		}
	}
  int dequeue() {
		int v = data[tail];
		tail = (tail + 1) % data.length;
		return v;
	}

	boolean isEmpty() {
		return head == tail;
	}
}
