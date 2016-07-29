/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 29 Jul 2016 08:05:36 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {
    private static final int MO = (int) (1e9 + 7);
    int mo, d;
    int[][][] dp, vis;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      mo = in.nextInt(); d = in.nextInt();
      String a = in.next(), b = in.next();
      dp = new int[a.length() + 5][mo][2];
      vis = new int[a.length() + 5][mo][2];
      a = new StringBuffer(a).reverse().toString();
      b = new StringBuffer(b).reverse().toString();
      out.println(solve(b, b.length() - 1, 0, 0, 0) - solve(a, a.length() - 1, 0, 0, 0) + check(a));
    }

    private int solve(String a, int pos, int mod, int has, int less) {
      if (pos < 0) {
        return mod == 0 ? 1 : 0;
      }
      else if (less != 0 && vis[pos][mod][has] != 0) return dp[pos][mod][has];
      else {
        if (less != 0) {
          vis[pos][mod][has] = 1;
          for (int i = 0; i < 10; i++) {
            if ((pos & 1) == 0 && i == d) continue;
            int nh = has != 0 || ((pos & 1) != 0 && i == d) ? 1 : 0;
            dp[pos][mod][has] += solve(a, pos - 1, (mod * 10 + i) % mo, nh, 1);
            dp[pos][mod][has] %= MO;
          }
          return dp[pos][mod][has];
        }
        else {
          int ans = 0;
          assert pos >= 0 && pos < a.length();
          for (int i = 0; i < (int) (a.charAt(pos) - '0' + 1); i++) {
            if((pos & 1) == 0 && i == d) continue;
            int nh = has != 0 || ((pos & 1) != 0 && i == d) ? 1 : 0;
            ans += solve(a, pos - 1, (mod * 10 + i) % mo, nh, i == (int) (a.charAt(pos) - '0') ? 1 : 0);
            ans %= MO;
          }
          return ans;
        }
      }
    }

    private int check(String a) {
      for (int i = 0; i < a.length(); i++) {
        if ((i & 1) == 0 && a.charAt(i) == (char) ('0' + d)) return 0;
      }
      return 1;
    }
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
