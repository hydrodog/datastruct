import java.io.FileReader;
import java.util.Random;
import java.util.Scanner;

public class Heapsort {
	public static void match(int x[], int parent, int n) {
		int left = 2*parent + 1;
		int right = 2*parent + 2;
		if (left >= n)
			return;
		if (right >= n) {
			if (x[left] > x[parent]) {
				int temp = x[left];
				x[left] = x[parent];
				x[parent] = temp;
				match(x, left, n);
			}
			return;
		}

		if (x[left] > x[right]) {
			if (x[left] > x[parent]) {
				int temp = x[left];
				x[left] = x[parent];
				x[parent] = temp;
				match(x, left, n);
			}
		} else {
			if (x[right] > x[parent]) {
				int temp = x[right];
				x[right] = x[parent];
				x[parent] = temp;
				match(x, right, n);
			}
		}
	}

	public static void makeheap(int x[], int n) {
		for (int i = n / 2; i >= 0; i--)
	    match(x, i, n);		
	}

	public static void reformHeap(int x[], int n) {
		int temp = x[0];
		x[0] = x[n-1];
		x[n-1] = temp;
		match(x, 0, n);
	}

	public static void heapsort(int x[]) {
		int n = x.length;
		makeheap(x, n);
		for (int i = n/2; i >= 0; i--)
			reformHeap(x, n--);
	}

	public static void makeRandom(int x[]) {
		Random r = new Random(0);
		final int n = x.length;
		for (int i = 0; i < n; i++)
			x[i] = r.nextInt(n)+1;
	}
		
	public static void main(String[] a) throws Exception {
		Scanner s = new Scanner(new FileReader("hw3.dat"));
		
		int n = s.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; i++)
			x[i] = s.nextInt();
		heapsort(x);
		
		s.close();
	}
}
