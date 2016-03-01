public class GrowArray {
	private int[] p;
	private int used;
	// this should double the size of your list
  private	void grow() {

	}
	public GrowArray() {
		p = new int[1];
		used = 0;
	}
	GrowArray(int capacity) {
		p = new int[capacity];
		used = 0;
	}
	public void addStart(int v) { // O(   )
	}
	
 	public void addEnd(int v) {  //O(    )
		if (used == size)
			grow();
		// O(1)
	}
  public int getCapacity() {
    return p.length;
	}

	public int getUsed() {
		return used;
	}
	int get(int i) { //O(1)
		return p[i];
	}
  void set(int i, int v) { // O(1)
		p[i] = v;
	}
	
};

int main() {
	GrowArray a = new GrowArray();
	for (int i = 0; i < 1000000; i++)
		a.add(i);
}



	

	
	
