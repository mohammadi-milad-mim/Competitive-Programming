import java.io.*;
import java.util.*;

public class jeroen {
	static int n;
	
	public static void main(String[] args) throws IOException {
		// Read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.valueOf(in.readLine());
		String[] ps = in.readLine().split(" ");
		int ar = Integer.valueOf(ps[0]);
		int ac = Integer.valueOf(ps[1]);
		ps = in.readLine().split(" ");
		int br = Integer.valueOf(ps[0]);
		int bc = Integer.valueOf(ps[1]);
		int[] mr = new int[n];
		int[] mc = new int[n];
		for(int i = 0; i < n; i++) {
			ps = in.readLine().split(" ");
			mr[i] = Integer.valueOf(ps[0]);
			mc[i] = Integer.valueOf(ps[1]);
		}

		// Lookup table with all valid moves, 
		HashSet<Long> moves = new HashSet<Long>();
		for(int i = 0; i < n; i++)
			moves.add(packMove(mr[i], mc[i]));

		// Check whether Alice can win
		for(int i = 0; i < n; i++) {
			if( (br == ar + mr[i] && bc == ac + mc[i]) // single step
				|| (inBoard(ar+mr[i], ac+mc[i]) && moves.contains(packMove(br-(ar+mr[i]), bc-(ac+mc[i]))))) { // two steps
				System.out.println("Alice wins");
				return;
			}
		}
		
		// Random trying, if there are free spots we have 50% chance of finding them
		Random rand = new Random(1337);
		for(int j = 0; j < 100; j++) {
			int r = 1 + rand.nextInt(n);
			int c = 1 + rand.nextInt(n);
			if(r == br && c == bc) continue;
			boolean possible = true;
			for(int i = 0; i < n; i++) {
				if( (r == br + mr[i] && c == bc + mc[i]) // single step
					|| (inBoard(br+mr[i],bc+mc[i]) && moves.contains(packMove(r-(br+mr[i]), c-(bc+mc[i]))))) {
					possible = false;
					break;
				}
			}

			if(possible) {
				System.out.println("tie " + r + " " + c);
				return;
			}
		}

		// Found nothing, so it is likely not possible at all
		System.out.println("Bob wins");
	}

	// Util for storing moves as a single number
	static long packMove(int r, int c) {
		return (r + n) * ((long)n * 2 + 1) + (c + n);
	}

	static boolean inBoard(int r, int c) {
		return 1 <= r && r <= n && 1 <= c && c <= n;
	}
}
