public class Hashmap {
	private int table[];
	private int used;
	private int limit;
	private int[] hist;
	private void grow() {
	}
	
	public Hashmap(int initialSize) {
		int i;
		for (i = 1; i <= initialSize; i *= 2)
			;
		table = new int[i];
		used = 0;
		limit = i / 2;
		hist = new int[50];
	}

	public Hashmap() {
		this(16);
	}
	public int hash(int v) {
		return v & (table.length-1); // Bob burtle's trick (MUST HAVE n=2^k)
	}
	public void add(int v) {
 		used++;
		if (used > limit)
			grow();
		int i = hash(v);
		int count = 0;
		while (table[i] != 0) {
			i = (i + 1) % table.length; // the slow way  & is fasters
			count++;
			if (count >= 50)
				count  = 49;
			hist[count]++;
		}
		
		table[i] = v;
	}
	public boolean contains(int v) {
		int i = hash(v);
 		while (table[i] != 0) {
			if (table[i] == v)
				return true;
			i = (i + 1) % table.length;
		}
	}

}
