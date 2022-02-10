import java.util.*;
import java.io.*;

public class Alex_fast_io {

	public static void main(String[] args) throws IOException {
		CustomScanner sc = new CustomScanner();
		final int n = sc.nextInt(), q = sc.nextInt();
		final int N  = 3*n*n + 1, top = N - 1;
		ArrayList<Long> seq = new ArrayList<Long>(N);
		for(int i = 0; i < n; ++i) {
			seq.add(sc.nextLong());
		}
		for(int i = n; i < N; ++i) {
			long best = Long.MAX_VALUE;
			for(int j = i; j > i / 2; --j) {
				best = Math.min(seq.get(j - 1) + seq.get(i - j), best);
			}
			seq.add(best);
		}

		int step = 1;
		long diff = 0;
		boolean ok = false;
		final int upper_bound = N - n*n;
		for(; !ok; ++step) {
			ok = true;
			diff = seq.get(top) - seq.get(top - step);
			for(int i = 0; i < upper_bound; ++i) {
				ok &= (seq.get(top - i) - seq.get(top - i - step) == diff);
			}
		}
		--step;

		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		for(int i = 0; i < q; ++i) {
			int query = sc.nextInt() - 1;
			if(query < N) {
				out.println(seq.get(query));
			} else {
				int num_steps = (query - N)/step + 1;
				out.println(seq.get(query - num_steps*step) + num_steps*diff);
			}
		}
		out.flush();
	}

	private static class CustomScanner{
		BufferedReader br;
		StringTokenizer st;

		public CustomScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() throws IOException {
			while(st == null || !st.hasMoreElements()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		int nextInt() throws IOException {return Integer.parseInt(next()); }
		
		long nextLong() throws IOException {return Long.parseLong(next()); }
	}

}
