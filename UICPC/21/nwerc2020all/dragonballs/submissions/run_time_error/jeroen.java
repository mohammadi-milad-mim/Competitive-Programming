import java.io.*;
import java.util.*;

public class jeroen {
	static final int MAXX = 1000000;
	static final int MAXY = 1000000;
	static BufferedReader in;
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(in.readLine());
		for(int i = 0; i < n; i++) findBall();
	}

	public static void findBall() throws Exception {
		long d0 = doGuess(0,0);
		if(d0 == 0) return;
		long d1 = doGuess(1,0);
		if(d1 == 0) return;
		if(d0 < d1) {
			if(doGuess(0,sqrtLong(d0)) != 0) throw new Exception("I failed the math");
			return;
		}
		long x = (d0 - d1 + 1) / 2; // difference should be 2*x-1
		long y = sqrtLong(d0 - x*x);
		if(doGuess(x,y) != 0) throw new Exception("I failed the math");
	}

	public static long sqrtLong(long x) {
		return (long)Math.round(Math.sqrt(x));
	}

	public static long doGuess(long x, long y) throws IOException {
		System.out.println(x + " " + y);
		System.out.flush();
		return Long.valueOf(in.readLine());
	}
}
