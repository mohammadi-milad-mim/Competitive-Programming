import java.util.*;
import java.io.*;

public class per_nlogn {
    static int n, logn = 0;;

    static void min_jmp(long T[][], int i, long v0) {
        T[i][0] = v0;
        for (int b = 0; b < logn; ++b)
            T[i][b+1] = Math.min(T[i][b], T[Math.max(i-(1<<b), 0)][b]);
    }

    static int prev_smaller(long T[][], int i, long v) {
        for (int b = logn; b >= 0 && i >= 0; --b)
            if (T[i][b] >= v) i -= 1<<b;
        return Math.max(i, -1);
    }

    public static void main(String args[]) {
        Kattio io = new Kattio(System.in, System.out);
        n = io.getInt();
        while ((2<<logn) <= n) ++logn;

        long a[] = new long[n], a_sum[] = new long[n+1];
        for (int i = 0; i < n; ++i) {
            a[i] = io.getInt();
            a_sum[i+1] = a_sum[i] + a[i];
        }

        long surplus[][] = new long[n+1][logn+1], deficit[][] = new long[n+1][logn+1], opt_glide[][] = new long[n+1][logn+1];

        long opt[] = new long[n+1];

        for (int i = 1; i <= n; ++i) {
            opt[i] = Math.max(a_sum[i]-1, 0);
            if (a[i-1] == 0) opt[i] = Math.min(opt[i], opt[i-1]);
            int r = prev_smaller(surplus, i-1, a_sum[i]-i+1);
            if (r >= 0) {
                int l = prev_smaller(deficit, r-1, i-a_sum[i]), b = 0;
                while ((2<<b) < r-l) ++b;
                opt[i] = Math.min(opt[i],
                                  2*a_sum[i] - i - 1 + Math.min(opt_glide[r][b],
                                                                opt_glide[l+(1<<b)][b]));
            }

            min_jmp(surplus, i, a_sum[i]-i);
            min_jmp(deficit, i, i-a_sum[i]);
            min_jmp(opt_glide, i, opt[i] - 2*a_sum[i] + i);
        }
        
        long ans = 1L<<60;
        for (int i = 1; i <= n; ++i)
            ans = Math.min(ans, opt[i] + Math.max(a_sum[n] - a_sum[i] - 1, 0L));
        System.out.println(ans);
    }
}

/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
