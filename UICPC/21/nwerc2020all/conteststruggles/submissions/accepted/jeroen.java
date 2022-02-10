import java.io.*;
import java.util.*;

public class jeroen {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ps = in.readLine().split(" ");
		int n = Integer.valueOf(ps[0]);
		int k = Integer.valueOf(ps[1]);
		ps = in.readLine().split(" ");
		double d = Double.valueOf(ps[0]);
		double s = Double.valueOf(ps[1]);

		double ans = (d*n - s*k) / (n - k);
		if(ans < 0 || ans > 100)
			System.out.println("impossible");
		else
			System.out.println(ans);
	}
}
