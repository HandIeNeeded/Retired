/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 08 Aug 2016 10:45:33 PM CST
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      
    }
  }

  static class DinicSolver {
    static int N = 100005, M = 100005, INF = 0x3f3f3f3f;
    int[] first, next, end, cap, current, level;
    int source, sink, edge;

    void add(int x, int y, int z) {
      next[++edge] = first[x];
      first[x] = edge;
      end[edge] = y;
      cap[edge] = z;
    }

    void Add(int x, int y, int z) {
      this.add(x, y, z);
      this.add(y, x, 0);
    }

    void Init(int source, int sink) {
      this.source = source;
      this.sink = sink;
      next = new int[M << 1];
      end = new int[M << 1];
      cap = new int[M << 1];
      first = new int[N];
      current = new int [N];
      level = new int[N];
      edge = 1;
    }

    boolean Bfs() {
      Queue<Integer> que = new ArrayDeque<>();
      que.add(source);
      level[source] = 1;
      while (!que.isEmpty())  {
        int x = que.poll();
        for (int go = first[x]; go != 0; go = next[go]) if (cap[go] > 0) {
          int y = end[go];
          if (level[y] == 0) {
            level[y] = level[x] + 1;
            que.add(y);
          }
        }
      }
      return level[sink] != 0;
    }

    int Dfs(int x, int flow) {
      int answer = 0, tmp = 0;
      if (x == sink || flow == 0) return flow;
      for (; current[x] != 0; current[x] = next[current[x]]) if (cap[current[x]] > 0) {
        int y = end[current[x]];
        if (level[y] == level[x] + 1 && (tmp = this.Dfs(y, Math.min(flow, cap[current[x]]))) > 0) {
          cap[current[x]] -= tmp;
          cap[current[x] ^ 1] += tmp;
          answer += tmp;
          flow -= tmp;
          if (flow == 0) return answer;
        }
      }
      return answer;
    }

    int Dinic() {
      int answer = 0;
      while (this.Bfs()) {
        for (int i = 0; i < current.length; i++) current[i] = first[i];
        answer += this.Dfs(source, INF);
      }
      return answer;
    }

    public static void main(String[] args) {
      System.out.println("Dinic Tester");
      DinicSolver tester = new DinicSolver();
      tester.Init(0, 3 + 1);
      tester.Add(1, 2, 3);
      tester.Add(2, 1, 3);
      System.out.println(tester.Dinic());
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
