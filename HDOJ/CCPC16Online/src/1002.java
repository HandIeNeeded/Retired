/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 15 Aug 2016 07:37:51 PM CST
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
    static final int N = 2000;
    static final int MO = (int) (1e9 + 7);
    static int[] prime = new int[N], visited = new int[N];
    static int tot;

    static {
      for (int i = 2; i < N; i++) {
        if (visited[i] == 0) prime[tot++] = i;
        for (int j = 0; j < tot && prime[j] * i < N; j++) {
          visited[i * prime[j]] = prime[j];
          if (i % prime[j] == 0) break;
        }
      }
    }

    byte[][] marks;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int t = in.nextInt();
      for (int ca = 1; ca <= t; ca++) {
        int n = in.nextInt();
        marks = new byte[n][tot];
        for (int i = 0; i < n; i++) {
          long x = in.nextLong();
          for (int j = 0; j < tot; j++) {
            byte cnt = 0;
            while (x % prime[j] == 0) {
              x /= prime[j];
              cnt ^= 1;
            }
            marks[i][j] = cnt;
          }
        }
        //for (int i = 0; i < 3; i++) {
        //  for (int j = 0; j < 3; j++) {
        //    out.printf(marks[i][j] + " ");
        //  }
        //  out.println();
        //}
        int rank = 0;
        for (int i = 0; i < tot; i++) {
          int find = -1;
          for (int j = rank; j < n; j++) {
            if (marks[j][i] != 0) {
              find = j;
              break;
            }
          }
          if (find >= 0) {
            byte[] tmp = marks[rank];
            marks[rank] = marks[find];
            marks[find] = tmp;
            for (int k = 0; k < n; k++) if (k != rank) {
              if (marks[k][i] != 0) {
                for (int s = 0; s < tot; s++) {
                  marks[k][s] ^= marks[rank][s];
                }
              }
            }
            rank++;
          }
        }
        out.println("Case #" + ca + ":");
        out.println(powd(n - rank) - 1);
      }
    }

    private long powd(int y) {
      long ans = 1, x = 2;
      while (y > 0) {
        if ((y & 1) != 0) ans = 1L * ans * x % MO;
        x = 1L * x * x % MO;
        y >>= 1;
      }
      return ans;
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
