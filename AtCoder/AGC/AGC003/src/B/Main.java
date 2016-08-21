/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 21 Aug 2016 08:07:38 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int[] a = new int[n + 1];
      long[][] dp = new long[n + 1][2];
      for (int i = 0; i < n; i++) {
        a[i + 1] = in.nextInt();
      }
      for (int i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = -1;
      }
      dp[0][0] = 0;
      for (int i = 1; i <= n; i++) {
        if (dp[i - 1][0] >= 0) {
          dp[i][0] = dp[i - 1][0] + a[i] / 2;
          if (a[i] > 0) dp[i][1] = dp[i - 1][0] + (a[i] - 1) / 2;
        }
        if (dp[i - 1][1] >= 0) {
          dp[i][0] = Math.max(dp[i][0], dp[i - 1][1] + a[i] / 2);
          if (a[i] > 0) dp[i][1] = Math.max(dp[i][1], dp[i - 1][1] + a[i] / 2);
          if (a[i] > 0) dp[i][0] = Math.max(dp[i][0], dp[i - 1][1] + (a[i] - 1) / 2 + 1);
          if (a[i] > 1) dp[i][1] = Math.max(dp[i][1], dp[i - 1][1] + (a[i] - 2) / 2 + 1);
        }
      }
      long ans = Math.max(dp[n][0], dp[n][1]);
      out.println(ans);
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

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }
  }
}
