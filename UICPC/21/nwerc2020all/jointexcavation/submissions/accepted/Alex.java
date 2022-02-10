import java.util.*;

public class Alex {

	public static int a;
	public static int b;
	public static HashSet<Integer> seen;
	public static HashSet<Integer> sub_a;
	public static ArrayList<HashSet<Integer>> graph;

	public static boolean check(int index) {
		if(a==b) {
			System.out.println((graph.size() - 2*a - 1) + " " + a);
			System.out.print(index);
			return true;
		}
		return false;
	}

	public static boolean DFS(int index) {
		--b;
		seen.add(index);
		if(check(index))
			return true;

		for(int next : graph.get(index)) {
			if(!seen.contains(next)) {
				if(DFS(next)) {
					System.out.print(" " + index);
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

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
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

		DFS(halls);
		System.out.println();
		for(int i = 1; i <= halls; ++i) {
			if(!seen.contains(i)) {
				System.out.print(i + " ");
			}
		}
		System.out.println();
		for(int i : sub_a) {
			System.out.print(i + " ");
		}
		System.out.println();
	}
}
