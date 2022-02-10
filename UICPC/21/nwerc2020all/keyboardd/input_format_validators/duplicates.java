import java.io.*;
import java.util.*;

public class duplicates {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String orig = in.readLine();
		String dupl = in.readLine();

		// First find all duplicated characters
		int[] count = new int[200];
		for(char c : orig.toCharArray()) count[c]++;
		for(char c : dupl.toCharArray()) count[c]--;

		// Check that we changed at least something
		int numDiff = 0;
		for(char c : orig.toCharArray())
			if(count[c] < 0)
				numDiff++;
		if(numDiff == 0) {
			System.out.println("No duplicated characters");
			return;
		}

		// Now check that the strings match
		int i = 0, j = 0;
		while(i < orig.length() && j < dupl.length()) {
			char c = orig.charAt(i);
			if(c != dupl.charAt(j)) {
				System.out.println("'" + c + "' != '" + dupl.charAt(j) + "'");
				return;
			}
			if(count[c] < 0) {
				j++;
				if(c != dupl.charAt(j)) {
					System.out.println("Character '" + c + "' is not duplicated.");
					return;
				}
			}
			i++; j++;
		}
		if(i != orig.length() || j != dupl.length()) {
			System.out.println("Not all input was consumed.");
			return;
		}

		// Accept
		System.exit(42);
	}
}
