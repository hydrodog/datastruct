import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Iterator;

public class TestJavaIterators {
	public static void main(String[] a) {
		LinkedList<Integer> x = new LinkedList<Integer>();
		for (int i = 0; i < 10; i++)
			x.add(i);

		for (Iterator i = x.iterator(); i.hasNext(); ) {
			System.out.print(i.next());
		}
	}
}
