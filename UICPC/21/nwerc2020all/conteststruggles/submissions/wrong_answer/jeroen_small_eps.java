import java.io.*;
import java.util.*;

public class jeroen_small_eps {
	static double eps = 1e-5;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ps = in.readLine().split(" ");
		int n = Integer.valueOf(ps[0]);
		int k = Integer.valueOf(ps[1]);
		ps = in.readLine().split(" ");
		double a = Double.valueOf(ps[0]);
		double s = Double.valueOf(ps[1]);

		double ans = (a*n - s*k) / (n - k);
		if(ans < -eps || ans > 100 + eps)
			System.out.println("impossible");
		else
			System.out.println(ans);
	}
}
