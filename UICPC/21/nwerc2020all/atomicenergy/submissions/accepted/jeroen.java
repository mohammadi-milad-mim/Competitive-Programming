import java.io.*;
import java.util.*;

public class jeroen {
	public static void main(String[] args) throws IOException {
		// Read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ps = in.readLine().split(" ");
		int n = Integer.valueOf(ps[0]);
		int q = Integer.valueOf(ps[1]);
		long[] a = new long[n];
		ps = in.readLine().split(" ");
		for(int i = 0; i < n; i++)
			a[i] = Integer.valueOf(ps[i]);
		long[] qs = new long[q];
		for(int i = 0; i < q; i++)
			qs[i] = Integer.valueOf(in.readLine());

		// Precompute in O(n^3), so let's hope this is far enough
		long[] dp = new long[n*n*2];
		for(int i = 0; i < n; i++) dp[i+1] = a[i];
		for(int i = n+1; i < dp.length; i++) {
			dp[i] = dp[i-1] + dp[1];
			for(int j = 1; j + j <= i; j++)
				dp[i] = Math.min(dp[i], dp[j] + dp[i-j]);
		}

		// Answer the queries
		for(int i = 0; i < q; i++) {
			long answer = Long.MAX_VALUE;

			// Find the k which we can split off many times leading to the best answer
			for(int k = 1; k <= n; k++) {
				// For everything >= dp.length, we split off k many times
				long nsplitoff = 0;
				if(qs[i] >= dp.length)
					nsplitoff = (qs[i] - dp.length + k) / k;
				answer = Math.min(answer, dp[(int)(qs[i]-k*nsplitoff)] + nsplitoff * dp[k]);
			}
			System.out.println(answer);
		}
	}
}
