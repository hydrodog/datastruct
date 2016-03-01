public class BadGrowArray {
	private int[] p;
	public BadGrowArray() {
		p = new int[0];
	}
	public void addEnd(int v) {
		int[] temp = p;
		p = new int[temp.length+1];
		for (int i = 0; i < temp.length; i++)
			p[i] = temp[i];
		p[temp.length] = v;
	}
	
	public void addStart(int v) {
	}

	public int size() {
		return p.length;
	}

	public int get(int i) {
		return p[i];
	}

	public static void main(String[] a) {
		BadGrowArray list = new BadGrowArray();
		final int n = 10;
		for (int i = 0; i < n; i++)
			list.addEnd(i);
		for (int i = 0; i < n; i++)
			System.out.print(list.get(i) +  " ");
	}
}
	
