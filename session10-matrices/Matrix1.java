public class Matrix1 {
	private double[][] m;

	public Matrix1(int rows, int cols) {
		m = new double[rows][cols];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				m[i][j] = 1;
	}

	public static void main(String[] a) {
		int n = Integer.parseInt(a[0]);
		for (int i = 0; i < 5; i++) {
			Matrix1 m = new Matrix1(n,n);
		}
		long t0 = System.currentTimeMillis();
		for (int i = 0; i < 100; i++) {
			Matrix1 m1 = new Matrix1(n,n);
		}
		long t1 = System.currentTimeMillis();
		System.out.println(t1 - t0);
	}
}
