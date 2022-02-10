import java.util.*;

public class Alex {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
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

		for(int i = 0; i < q; ++i) {
			int query = sc.nextInt() - 1;
			if(query < N) {
				System.out.println(seq.get(query));
			} else {
				int num_steps = (query - N)/step + 1;
				System.out.println(seq.get(query - num_steps*step) + num_steps*diff);
			}
		}
	}
}
