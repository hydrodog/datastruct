public class Matrix2 {
	private double[] m;

	public Matrix2(int rows, int cols) {
		m = new double[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			m[i] = 1;
	}

	public static void main(String[] a) {
		int n = Integer.parseInt(a[0]);
		for (int i = 0; i < 5; i++) {
			Matrix2 m = new Matrix2(n,n);
		}
		long t0 = System.currentTimeMillis();
		for (int i = 0; i < 100; i++) {
			Matrix2 m1 = new Matrix2(n,n);
		}
		long t1 = System.currentTimeMillis();
		System.out.println(t1 - t0);
	}
}
