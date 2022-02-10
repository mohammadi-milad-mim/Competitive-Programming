import java.io.*;
import java.util.*;

public class jeroen {
	static final int MAXX = 1000000;
	static final int MAXY = 1000000;
	static BufferedReader in;

	// Truly random, decided by smashing on my keyboard
	static final int RANDX = 98734;
	static final int RANDY = 23874;
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(in.readLine());
		for(int i = 0; i < n; i++) findBall();
	}

	public static void findBall() throws Exception {
		long d0 = doGuess(RANDX,RANDY);
		if(d0 == 0) return;
		long d1 = doGuess(RANDX+1,RANDY);
		if(d1 == 0) return;
		
		long x = d0 < d1
			? RANDX - (d1 - d0 + 1) / 2 + 1
			: RANDX + (d0 - d1 + 1) / 2; // difference should be 2*x-1
		long dy = sqrtLong(d0 - (RANDX-x)*(RANDX-x));
		long y1 = RANDY - dy;
		if(y1 >= 0 && doGuess(x,y1) == 0) return;
		long y2 = RANDY + dy;
		if(y2 <= MAXY && doGuess(x,y2) == 0) return;

		throw new Exception("Bad luck");
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
