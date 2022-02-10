import java.io.*;
import java.util.*;

public class Alex_fast_io {

	public static int a;
	public static int b;
	public static HashSet<Integer> seen;
	public static HashSet<Integer> sub_a;
	public static ArrayList<HashSet<Integer>> graph;
	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	public static boolean check(int index) throws IOException {
		if(a==b) {
			out.println((graph.size() - 2*a - 1) + " " + a );
			out.print(index + "");
			return true;
		}
		return false;
	}

	public static boolean DFS(int index) throws IOException {
		--b;
		seen.add(index);
		if(check(index))
			return true;

		for(int next : graph.get(index)) {
			if(!seen.contains(next)) {
				if(DFS(next)) {
					out.print(" " + index);
					return true;
				}
				if(check(index))
					return true;
			}
		}

		++a;
		sub_a.add(index);
		return false;
	}

	public static void main(String[] args) throws IOException {
		CustomScanner sc = new CustomScanner();
		int halls = sc.nextInt(), tunnels = sc.nextInt();
		a = 0;
		b = halls;
		seen = new HashSet<Integer>();
		sub_a = new HashSet<Integer>();
		graph = new ArrayList<HashSet<Integer>>(halls + 1);
		for(int i = 0; i <= halls; ++i) {
			graph.add(new HashSet<Integer>());
		}
		while(tunnels-- > 0) {
			int a = sc.nextInt(), b = sc.nextInt();
			graph.get(a).add(b);
			graph.get(b).add(a);
		}

		DFS(1);
		out.println();;
		for(int i = 1; i <= halls; ++i) {
			if(!seen.contains(i)) {
				out.print(i + " ");
			}
		}
		out.println();
		for(int i : sub_a) {
			out.print(i + " ");
		}
		out.println();
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
	}
}
