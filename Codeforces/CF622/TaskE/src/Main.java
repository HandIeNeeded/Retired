/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 30 Jul 2016 12:40:05 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {
    ArrayList<Integer>[] edges;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      edges = new ArrayList[n + 1];
      for (int i = 1; i <= n; i++) {
        edges[i] = new ArrayList<>();
      }
      for (int i = 0; i < n - 1; i++) {
        int x = in.nextInt(), y = in.nextInt();
        edges[x].add(y);
        edges[y].add(x);
      }
      int answer = 0;
      for (int x: edges[1]) {
        Pair result = dfs(x, 1);
        answer = Math.max(result.second + 1, answer);
      }
      out.println(answer);
    }

    private Pair dfs(int node, int p) {
      ArrayList<Pair> tmp = new ArrayList<>();
      for (int x: edges[node]) if (x != p) {
        tmp.add(dfs(x, node));
      }
      if (tmp.size() == 0) {
        return new Pair(1, 1);
      }
      else {
        Collections.sort(tmp);


        return new Pair(1, 1);
      }
    }
  }

  static class Pair implements Comparable<Pair> {
    public final int first;
    public final int second;

    public Pair(int x, int y) {
      first = x;
      second = y;
    }

    public int compareTo(Pair rhs) {
      if (first != rhs.first) return first - rhs.first;
      else return second - rhs.second;
    }

    public Pair add(Pair rhs) {
      if (rhs.first <= second) {

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
    
    public long nextLong() {
      return Long.parseLong(next());
    }

    public int nextInt() {
  }
}

