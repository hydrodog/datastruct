import java.util.Arrays;

public class Heaps3 {
	private static int[] v;
	private static void swap(int i, int j) {
		int t = v[i];
		v[i] = v[j];
		v[j] = t;
	}
	private static int count = 0;
	private static void doit() {
		count++;
		//		System.out.println(Arrays.toString(v));
	}
 
	public static void permute(int n) {
		if (n == 1) {
			doit();
		}
		else {
			if (n % 2 == 1) {
				for (int i = 0; i < n; i++) {
					permute(n - 1);
 					swap(0, n - 1);
				}
			} else {
				for (int i = 0; i < n; i++) {
					permute(n - 1);
 					swap(i, n - 1);
				}
			}
		}
	}

	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
		v = new int[n];
		for (int i = 0; i < n; i++)
			v[i] = i+1;
		long t0 = System.currentTimeMillis();
		permute(n);
		long t1 = System.currentTimeMillis();
		System.out.println(count);
		System.out.println("Elapsed: " + (t1-t0));
	}
}
