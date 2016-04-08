import java.util.Arrays;

public class Heaps2 {
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
		if (n == 3) {
			doit();   //123
			int v0 = v[0], v1 = v[1], v2 = v[2];
			v[0] = v1; v[1] = v0; doit(); //213
			v[0] = v2; v[2] = v1; doit(); //312
			v[0] = v0; v[1] = v2; doit(); //132
			v[0] = v1; v[2] = v0; doit(); //231
			v[0] = v2; v[1] = v1; doit(); //31?
			return;
		}

		for (int i = 0; i < n; i++) {
			permute(n - 1);
			if (n % 2 == 1) {
				swap(0, n - 1);
			} else {
				swap(i, n - 1);
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
