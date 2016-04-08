public class Tridiagonal {
	private double[] m;

	public Tridiagonal(int n) {
		m = new double[3*n-1];
	}
	public double get(int i, int j) { // O(1)
		if (Math.abs(i-j) > 1)
			return 0;
		//		return m[3*i + j - i + 1   ];
		//		return m[2*i + j + 1];
		return m[i + i + j];
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
