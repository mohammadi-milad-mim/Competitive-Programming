import java.io.*;
import java.util.*;

public class jeroen_intersectpast {
	static Car[] cars;

	public static void main(String[] args) throws IOException {
		// Read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(in.readLine());
		cars = new Car[n];
		for(int i = 0; i < n; i++) {
			String[] ps = in.readLine().split(" ");
			cars[i] = new Car(i+1, Long.valueOf(ps[0]), Long.valueOf(ps[1]));
		}
		Arrays.sort(cars);

		// Poor mans linked list
		int[] next = new int[n];
		int[] prev = new int[n];
		for(int i = 0; i < n - 1; i++) {
			next[i] = i + 1;
			prev[i + 1] = i;
		}
		prev[0] = -1;
		next[n-1] = n;

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
		TreeSet<Integer> nocrash = new TreeSet<Integer>();
		for(int i = 0; i < n; i++)
			if(!crashed[i])
				nocrash.add(cars[i].i);

		System.out.print(nocrash.size());
		for(int i : nocrash)
			System.out.print(" " + i);
		System.out.println();
	}

	static Intersection whenCrash(int i, int j) {
		// Search for t such that cars[i].x + cars[i].v * t == cars[j].x + cars[j].v * t
		if(cars[i].x == cars[j].x) return new Intersection(i, j, 0, 1);
		if(cars[i].v == cars[j].v) return null;
		return new Intersection(i, j, cars[i].x - cars[j].x, cars[j].v - cars[i].v);
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

	static class Car implements Comparable<Car> {
		public int i;
		public long x, v;

		public Car(int i, long x, long v) {
			this.i = i;
			this.x = x;
			this.v = v;
		}
		
		public int compareTo(Car other) {
			return Long.compare(x, other.x);
		}
	}
}
