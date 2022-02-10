import java.io.*;
import java.util.*;

public class jeroen_nosort {
	static long[] x, v;

	public static void main(String[] args) throws IOException {
		// Read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(in.readLine());
		x = new long[n];
		v = new long[n];
		for(int i = 0; i < n; i++) {
			String[] ps = in.readLine().split(" ");
			x[i] = Long.valueOf(ps[0]);
			v[i] = Long.valueOf(ps[1]);
		}

		// Poor mans linked list
		int[] next = new int[n];
		int[] prev = new int[n];
		for(int i = 0; i < n - 1; i++) {
			next[i] = i + 1;
			prev[i + 1] = i;
		}

		// Main logic, look at crashed from vehicles next to each other
		boolean[] crashed = new boolean[n];
		PriorityQueue<Intersection> Q = new PriorityQueue<Intersection>();
		for(int i = 0; i < n - 1; i++) {
			Intersection inter = whenCrash(i, i+1);
			if(inter != null) Q.add(inter);
		}

		while(!Q.isEmpty()) {
			Intersection sect = Q.poll();
			if(crashed[sect.i] || crashed[sect.j]) continue;
			crashed[sect.i] = crashed[sect.j] = true;
			int b = prev[sect.i];
			int a = next[sect.j];
			if(b >= 0 && a < n) {
				Intersection inter = whenCrash(b, a);
				if(inter != null) Q.add(inter);
			}
			if(b >= 0) next[b] = a;
			if(a < n)  prev[a] = b;
			
		}

		// And write output
		int nocrash = 0;
		for(int i = 0; i < n; i++)
			if(!crashed[i])
				nocrash++;

		System.out.print(nocrash);
		
		for(int i = 0; i < n; i++)
			if(!crashed[i])
				System.out.print(" " + (i+1));
		System.out.println();
	}

	static Intersection whenCrash(int i, int j) {
		// Search for t such that x[i] + v[i] * t == x[j] + v[j] * t
		if(x[i] == x[j]) return new Intersection(i, j, 0, 1);
		if(v[i] == v[j]) return null;
		long n = x[i] - x[j];
		long d = v[j] - v[i];
		if(Math.signum(n) != Math.signum(d)) return null;
		return new Intersection(i, j, n, d);
	}

	static class Intersection implements Comparable<Intersection> {
		// intersection happens at t = n / d
		public int i, j;
		public long n, d;

		public Intersection(int i, int j, long n, long d) {
			this.i = i;
			this.j = j;
			this.n = n;
			this.d = d;
		}
		
		public int compareTo(Intersection other) {
			// conceptually: if( n/d < other.n/other.d)
			if(n * other.d < other.n * d) return -1;
			if(n * other.d > other.n * d) return 1;
			return 0;
		}
	}
}
