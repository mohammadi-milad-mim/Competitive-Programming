import java.io.*;
import java.util.*;

public class jeroen {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(in.readLine());
		long[] a = new long[n];
		String[] ps = in.readLine().split(" ");
		for(int i = 0; i < n; i++) a[i] = Long.valueOf(ps[i]);

		Arrays.sort(a);
		int mid = n / 2;
		for(int i = 0; i < n; i++)
			System.out.print((i % 2 == 0 ? a[mid + (i/2)] : a[mid - ((i+1)/2)]) + " ");
		System.out.println();
	}
}
