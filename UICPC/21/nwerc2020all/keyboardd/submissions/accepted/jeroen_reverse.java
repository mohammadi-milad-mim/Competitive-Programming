import java.io.*;
import java.util.*;

public class jeroen_reverse {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String orig = in.readLine();
		String dupl = in.readLine();
		int[] count = new int[200];
		for(char c : orig.toCharArray()) count[c]++;
		for(char c : dupl.toCharArray()) count[c]--;
		for(char c = 199; c > 0; c--)
			if(count[c] < 0)
				System.out.print(c);
	}
}
