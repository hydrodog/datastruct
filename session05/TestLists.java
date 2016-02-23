import java.util.*;

public class TestLists {
	public static void test1(int n) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < n; i++)
			list.add(i);
	}

	public static void test2(int n) {
		ArrayList<Integer> list = new ArrayList<Integer>(n);
		for (int i = 0; i < n; i++)
			list.add(i);
	}

	public static void test3(int n, ArrayList<Integer> list) {
		for (int i = 0; i < n; i++)
			list.set(i, list.get(i)+1);
	}

	public static void main(String[] a) {
		int n = Integer.parseInt(a[0]);
		ArrayList<Integer> list = new ArrayList<Integer>(n);
		for(int i = 0; i < n; i++)
			list.add(i);
		//		test3(n, list);
		test1(n);
 		long t0 = System.currentTimeMillis();
		//		test3(n, list);
		test1(n);
		long t1 = System.currentTimeMillis();
		System.out.println(t1-t0);
	}
}
