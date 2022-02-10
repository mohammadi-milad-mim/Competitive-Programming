import java.io.*;
import java.util.*;

public class jeroen {
	public static void main(String[] args) throws IOException {
		// Read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ps = in.readLine().split(" ");
		int n = Integer.valueOf(ps[0]);
		int r = Integer.valueOf(ps[1]);
		int m = Integer.valueOf(ps[2]);
		Trick[] tricks = new Trick[m];
		for(int i = 0; i < m; i++) {
			ps = in.readLine().split(" ");
			tricks[i] = new Trick(Integer.valueOf(ps[0]),
								  Double.valueOf(ps[1]),
								  Integer.valueOf(ps[2]));
		}

		// Sort the tricks by time for convenience
		Arrays.sort(tricks);

		// Binary search for the answer, then check whether
		// this answer is possible
		double low = 0;
		double up = 1e50; // some big number, is this big enough?
		for(int it = 0; it < 500; it++) {
			double mid = (low + up) / 2;
			
			// dp[i][j] is expected time to spend
			// when at trick i with j seconds lost
			double[][] dp = new double[m+1][r];
			for(int i = 0; i < r; i++) dp[m][i] = 0;
			for(int i = m - 1; i >= 0; i--) {
				for(int j = 0; j < r; j++) {
					int timeToNext = i < m - 1 ? tricks[i+1].t - tricks[i].t : n - tricks[i].t;

					// Trick succeeds
					dp[i][j] = tricks[i].p * (timeToNext + dp[i+1][j]);

					// Trick fails, so we can pick
					double ifFail = mid; // restart
					if(n + j + tricks[i].l < r)
						ifFail = Math.min(ifFail, tricks[i].l + dp[i+1][j+tricks[i].l] + timeToNext);
					dp[i][j] += (1 - tricks[i].p) * ifFail;
				}
			}

			if(dp[0][0] + tricks[0].t <= mid) up = mid;
			else low = mid;
		}
		System.out.println((low+up)/2);
	}
}


class Trick implements Comparable<Trick> {
	int t, l;
	double p;

	public Trick(int t, double p, int l) {
		this.t = t;
		this.p = p;
		this.l = l;
	}

	public int compareTo(Trick other) {
		return Integer.compare(t, other.t);
	}
}
