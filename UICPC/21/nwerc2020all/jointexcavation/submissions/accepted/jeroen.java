import java.io.*;
import java.util.*;

public class jeroen {
	public static void main(String[] args) throws IOException {
		// Read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ps = in.readLine().split(" ");
		c = Integer.valueOf(ps[0]);
		int t = Integer.valueOf(ps[1]);
		int[] a = new int[t];
		int[] b = new int[t];
		for(int i = 0; i < t; i++) {
			ps = in.readLine().split(" ");
			a[i] = Integer.valueOf(ps[0]);
			b[i] = Integer.valueOf(ps[1]);
		}

		// Build graph in a convenient representation
		nb = new ArrayList[c];
		for(int i = 0; i < c; i++)
			nb[i] = new ArrayList<Integer>();
		for(int i = 0; i < t; i++) {
			nb[a[i]-1].add(b[i]-1);
			nb[b[i]-1].add(a[i]-1);
		}

		// DFS, start at an arbitrary node and wait until we
		// reach a solution.
		vis = new boolean[c];
		cur = new Stack<Integer>();
		nvis = 0;
		dfs(23325898 % c, 1);
	}

	private static int c, nvis;
	private static Stack<Integer> cur;
	private static boolean[] vis;
	private static ArrayList<Integer>[] nb;
	private static void dfs(int i, int d) {
		vis[i] = true;
		cur.push(i);		
		check();
		for(int j : nb[i]) {
			if(vis[j]) continue;
			dfs(j,d+1);
			check();
		}
		cur.pop();
		nvis++;
	}

	private static void check() {
		if(nvis * 2 + cur.size() == c) {
			boolean[] printed = new boolean[c];
			System.out.println(cur.size() + " " + nvis);
			for(int j : cur) {
				System.out.print((j+1)+" ");
				printed[j] = true;
			}
			System.out.println();
			for(int j = 0; j < c; j++) {
				if(!printed[j] && vis[j]) {
					System.out.print((j+1)+" ");
					printed[j] = true;
				}
			}
			System.out.println();
			for(int j = 0; j < c; j++) {
				if(!printed[j]) {
					System.out.print((j+1)+" ");
					printed[j] = true;
				}
			}
			System.out.println();
			System.exit(0);
		}
	}
}
