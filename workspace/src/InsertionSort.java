
public class InsertionSort {
	public static void sort(int [] x) {
		for (int i = 1; i < x.length; i++) {
			if (x[i] >= x[i-1])
				continue;
			int temp = x[i];
			int j;
			for (j = i-1; j >= 0; j--) {
				if (x[j] > temp)
					x[j+1] = x[j];
				else {
					break;
				}
			}
			x[j+1] = temp;
		}
	}	
}	
