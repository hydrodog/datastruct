public class Triangular {
	private double[] m;

	public Triangular(int n) {
		m = new double[n*(n+1)/2];
	}
	public double get(int i, int j) { // O(1)
		if (j > i)
			return 0;
		return m[i * (i+1)/2 + j];
	}

	public static void main(String[] a) {
		int n = Integer.parseInt(a[0]);
		for (int i = 0; i < 5; i++) {
			Triangular m = new Triangular(n);
		}
		long t0 = System.currentTimeMillis();
		for (int i = 0; i < 100; i++) {
			Triangular m1 = new Triangular(n);
		}
		long t1 = System.currentTimeMillis();
		System.out.println(t1 - t0);
	}
}
