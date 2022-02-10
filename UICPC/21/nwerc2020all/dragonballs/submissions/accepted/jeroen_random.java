import java.io.*;
import java.util.*;

public class jeroen_random {
	static final int MAXX = 1000000;
	static final int MAXY = 1000000;
	static BufferedReader in;
	static Random rand = new Random();
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(in.readLine());
		for(int i = 0; i < n; i++) findBall();
	}

	public static void findBall() throws Exception {
		long randx = rand.nextInt(MAXX);
		long randy = rand.nextInt(MAXY);
		long d0 = doGuess(randx,randy);
		if(d0 == 0) return;
		long d1 = doGuess(randx+1,randy);
		if(d1 == 0) return;
		
		long x = d0 < d1
			? randx - (d1 - d0 + 1) / 2 + 1
			: randx + (d0 - d1 + 1) / 2; // difference should be 2*x-1
		long dy = sqrtLong(d0 - (randx-x)*(randx-x));
		long y1 = randy - dy;
		if(y1 >= 0 && doGuess(x,y1) == 0) return;
		long y2 = randy + dy;
		if(y2 <= MAXY && doGuess(x,y2) == 0) return;

		// Failed, so we try again
		findBall();
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
