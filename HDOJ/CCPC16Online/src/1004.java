/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 14 Aug 2016 12:41:50 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskA solver = new TaskA();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int t = in.nextInt();
      int test = 1;
      for (int i = 0; i < t; i++) {
        int n = in.nextInt();
        int[] a = new int[n];
        int sum = 0, mx = 0;
        for (int j = 0; j < n; j++) {
          a[j] = in.nextInt();
          sum += a[j];
          mx = Math.max(mx, a[j]);
        }
        if (n == 1) {
          out.println("Case #" + test++ + ": " + Math.min(1, a[0] / 2));
          continue;
        }
        int lo = 0, hi = sum / 2 + 1;
        int tot = 0;
        if (mx > sum - mx) tot = 2 * (sum - mx) + 1;
        else tot = sum / 2 * 2;
        while (lo + 1 < hi) {
          int mid = (lo + hi) / 2;
          if (mid <= tot && 2 * mid <= sum) lo = mid;
          else hi = mid;
        }
        out.println("Case #" + test++ + ": " + lo);
      }
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
