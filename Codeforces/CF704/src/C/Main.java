/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 15 Aug 2016 09:31:51 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static final class Pair {
    public int first, second;
    Pair(int a, int b) {
      first = a; second = b;
    }
  }

  static class TaskC {
    ArrayList<Pair>[] edges;
    static final int MO = (int) (1e9 + 7);
    int[][][] dp;
    int[] mark, visited;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int m = in.nextInt(), n = in.nextInt();
      int need = 1;
      boolean has = false;
      dp = new int[n + 1][2][2];
      mark = new int[n + 1];
      visited = new int[n + 1];
      edges = new ArrayList[n + 1];
      for (int i = 1; i <= n; i++) edges[i] = new ArrayList<>();
      for (int i = 0; i < m; i++) {
        int type = in.nextInt();
        if (type == 1) {
          int x = in.nextInt();
          mark[Math.abs(x)] = x > 0 ? 1 : -1;
          visited[Math.abs(x)] = 2;
        } else {
          int x = in.nextInt(), y = in.nextInt();
          int z = Math.abs(x), w = Math.abs(y);
          visited[z] = visited[w] = 2;
          if (z == w) {
            if (x == y) {
              has = true;
              break;
            } else {
              visited[z] = 0; need ^= 1;
            }
          } else {
            int edge = (z == x ? 1 : 0) * 2 + (y == w ? 1 : 0);
            edges[z].add(new Pair(w, hash(i, edge)));
            edge = (y == w ? 1 : 0) * 2 + (x == z ? 1 : 0);
            edges[w].add(new Pair(z, hash(i, edge)));
          }
        }
      }
      long result = 1;
      for (int i = 1; i <= n; i++) {
        if (mark[i] != 0 && edges[i].size() == 0) {
          has = true; break;
        } else if (visited[i] == 0) {
          result <<= 1;
          result %= MO;
        }
      }
      if (has) {
        out.println(powd(2, n - 1));
        return ;
      }
      //1. chain
      int[] answer = {1, 0};
      for (int i = 1; i <= n; i++) {
        if (visited[i] != 3 && edges[i].size() == 1) {
          int[] res = calc(i);
          //out.println("Start at: " + i + " " + res[0] + " " + res[1]);
          answer = merge(answer, res);
        }
      }
      //2. circle
      for (int i = 1; i <= n; i++) {
        if (visited[i] != 3 && edges[i].size() == 2) {
          int[] res = calc(i);
          //out.println("Start at: " + i + " " + res[0] + " " + res[1]);
          answer = merge(answer, res);
        }
      }
      out.println(result * answer[need] % MO);
    }

    private long powd(long x, long y) {
      long ans = 1;
      for (; y != 0; y >>= 1) {
        if (y % 2 != 0) ans = ans * x % MO;
        x = x * x % MO;
      }
      return ans;
    }

    private int[] calc(int node) {
      //dp[node][xor sum][last value]
      int[] answer = {0, 0};
      int head = node;
      int need = mark[head];
      visited[head] = 3;
      for (int color = 0; color < 2; color++) {
        //System.out.println("Color: " + color);
        int x, idx, type;
        node = head;
        Pair edge = edges[node].get(0);
        x = edge.first;
        idx = decode(edge.second).first;
        type = decode(edge.second).second;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            dp[node][i][j] = 0;
          }
        }
        int start = 0;
        if (Math.abs(need) == 1) {
          //System.out.println("hehe" + node);
          if (need > 0) start ^= color;
          if (need < 0) start ^= 1 ^ color;
        }
        dp[node][start][color] = 1;
        //System.out.println("Node: " + node + "Type: " + type);
        //for (int i = 0; i < 2; i++) {
        //  for (int j = 0; j < 2; j++) {
        //    System.out.print(dp[node][i][j] + " ");
        //  }
        //  System.out.println();
        //}
        while (true) {
          visited[x] = 3;
          for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
              dp[x][i][j] = 0;
            }
          }
          for (int sum = 0; sum < 2; sum++) {
            for (int last = 0; last < 2; last++) {
              for (int now = 0; now < 2; now++) {
                int nl = last, nc = now;
                if (type < 2) nl ^= 1;
                if (type % 2 == 0) nc ^= 1;
                int newSum = sum ^ (nl | nc);
                if (Math.abs(mark[x]) == 1) {
                  if (mark[x] < 0) newSum ^= 1 ^ now;
                  if (mark[x] > 0) newSum ^= now;
                }
                dp[x][newSum][now] += dp[node][sum][last];
                dp[x][newSum][now] %= MO;
              }
            }
          }
          //System.out.println("Node: " + x + "Type: " + type);
          //for (int i = 0; i < 2; i++) {
          //  for (int j = 0; j < 2; j++) {
          //    System.out.print(dp[x][i][j] + " ");
          //  }
          //  System.out.println();
          //}
          //System.out.println(node + " " + x + " " + mark[x]);
          if (edges[x].size() == 1) break;
          boolean last = false;
          for (int i = 0; i < edges[x].size(); i++) {
            Pair newEdge = edges[x].get(i);
            int newNode, newIdx, newType;
            newNode = newEdge.first;
            newIdx = decode(newEdge.second).first;
            newType = decode(newEdge.second).second;
            if (newIdx == idx) continue;
            if (newNode == head) {
              last = true;
              break;
            }
            node = x; x = newNode; idx = newIdx; type = newType;
            break;
          }
          if (last) break;
        }
        if (edges[x].size() == 2) {
          int[] res = {0, 0};
          for (int sum = 0; sum < 2; sum++) {
            for (int last = 0; last < 2; last++) {
              int nl = last, nc = color;
              int newSum = sum ^ (nl | nc);
              res[newSum] += dp[x][sum][last];
              res[newSum] %= MO;
            }
          }
          for (int i = 0; i < 2; i++) {
            answer[i] += res[i];
            answer[i] %= MO;
          }
          continue;
        }
        int[] res = {0, 0};
        for (int i = 0; i < 2; i++) {
          res[i] = (dp[x][i][0] + dp[x][i][1]) % MO;
          answer[i] += res[i];
          answer[i] %= MO;
        }
      }
      return answer;
    }

    private int[] merge(int[] pre, int[] now) {
      assert pre.length == 2 && now.length == 2;
      int[] answer = new int[2];
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          answer[i ^ j] += (int) (1L * pre[i] * now[j] % MO);
          answer[i ^ j] %= MO;
        }
      }
      return answer;
    }

    private int hash(int idx, int type) {
      return idx << 2 | type;
    }

    private Pair decode(int x) {
      return new Pair(x >> 2, x & 3);
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
