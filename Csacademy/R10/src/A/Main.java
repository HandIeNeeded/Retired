/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 06 Aug 2016 07:12:59 PM CST
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
      int n = in.nextInt(), m = in.nextInt();
      int[][][] dp = new int[2][n][m], vis = new int[2][n][m];
      int[] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
      for (int i = 0; i < 2; i++) {
        int x = in.nextInt(), y = in.nextInt();
        x--; y--;
        Queue<Integer> q = new LinkedList<>();
        q.offer(x); q.offer(y);
        dp[i][x][y] = 0; vis[i][x][y] = 1;
        while (!q.isEmpty()) {
          x = q.poll(); y = q.poll();
          //out.println(x + " " + y);
          for (int j = 0; j < 4; j++) {
            int tx = x + dx[j], ty = y + dy[j];
            if (valid(tx, ty, n, m) && vis[i][tx][ty] == 0) {
              vis[i][tx][ty] = 1;
              dp[i][tx][ty] = dp[i][x][y] + 1;
              q.offer(tx);
              q.offer(ty);
            }
          }
        }
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (dp[0][i][j] == dp[1][i][j]) ans++;
        }
      }
      out.println(ans);
    }

    boolean valid(int x, int y, int n, int m) {
      return x >= 0 && x < n && y >= 0 && y < m;
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
