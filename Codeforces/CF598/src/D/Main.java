/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 10:46:16 AM CST
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
    static int width, height;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
      height = n; width = m;
      char[][] mp = new char[n][m + 1];
      int[][] visited = new int[n][m];
      int[] answer = new int[q + 1];
      for (int i = 0; i < n; i++) {
        mp[i] = in.next().toCharArray();
      }
      int now = 0;
      while (q-- > 0) {
        int x, y;
        x = in.nextInt(); y = in.nextInt();
        x--; y--;
        if (visited[x][y] == 0) {
          now++;
          Queue<Integer> que = new LinkedList<>();
          int cnt = 0;
          visited[x][y] = now;
          que.add(x); que.add(y);
          while (!que.isEmpty()) {
            int nx = que.poll(); 
            int ny = que.poll();
            for (int i = 0; i < 4; i++) {
              int tx = nx + dx[i];
              int ty = ny + dy[i];
              if (valid(tx, ty)) {
                if (visited[tx][ty] != 0) continue;
                if (mp[tx][ty] == '*') {
                  cnt++;
                }
                else {
                  visited[tx][ty] = now;
                  que.add(tx); que.add(ty);
                }
              }
            }
          }
          answer[now] = cnt;
        }
        out.println(answer[visited[x][y]]);
      }
    }

    boolean valid(int x, int y) {
      return x >= 0 && x < height && y >= 0 && y < width;
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
