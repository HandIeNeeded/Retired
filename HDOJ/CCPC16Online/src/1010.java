/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 14 Aug 2016 03:04:45 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  static final int K = 2;
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
    ArrayList<Integer>[] edges;
    int[] ans;
    Trie[] tr;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int t = in.nextInt();
      for (int ca = 1; ca <= t; ca++) {
        int n = in.nextInt();
        edges = new ArrayList[n + 1];
        tr = new Trie[n + 1];
        ans = new int[n + 1];
        for (int i = 1; i <= n; i++) {
          int x = in.nextInt();
          edges[i] = new ArrayList<>();
          tr[i] = new Trie();
          tr[i].insert(x);
        }
        for (int i = 0; i < n - 1; i++) {
          int x, y;
          x = in.nextInt(); y = in.nextInt();
          edges[x].add(y);
          edges[y].add(x);
        }
        dfs(1, 0);
        int q = in.nextInt();
        out.println("Case #" + ca + ":");
        for (int i = 0; i < q; i++) {
          int idx = in.nextInt();
          out.println(ans[idx]);
        }
      }
    }

    private void dfs(int x, int p) {
      for (int y: edges[x]) {
        if (y == p) continue;
        dfs(y, x);
        assert tr[x] != null && tr[y] != null;
        tr[x] = tr[x].merge(tr[x], tr[y]);
      }
      ans[x] = tr[x].numbers.size() < 2 ? -1 : tr[x].ans;
    }
  }

  static class Node {
    Node[] son;

    Node () {
      son = new Node[2];
    }
  }

  static class Trie {
    ArrayList<Integer> numbers;
    int ans;
    Node root;

    Trie () {
      root = new Node();
      numbers = new ArrayList<>();
      ans = 0;
    }

    void insert(int x) {
      Node now = root;
      numbers.add(x);
      for (int i = K; i >= 0; i--) {
        int idx = (x & (1 << i)) != 0 ? 1 : 0;
        if (now.son[idx] == null) now.son[idx] = new Node();
        now = now.son[idx];
      }
    }

    int query(int x) {
      Node now = root;
      int number = 0;
      assert now != null;
      for (int i = K; i >= 0; i--) {
        int idx = (x & (1 << i)) != 0 ? 1 : 0;
        if (now.son[idx] == null) idx ^= 1;
        number |= (idx << i);
        now = now.son[idx];
      }
      return number ^ x;
    }

    Trie merge(Trie a, Trie b) {
      if (a.numbers.size() < b.numbers.size()) {
        Trie tmp = a; a = b; b = tmp;
      }
      Trie res = a;
      res.ans = Math.max(a.ans, b.ans);
      for (int x: b.numbers) {
        int now = res.query(x);
        res.ans = Math.max(ans, now);
        res.insert(x);
      }
      return res;
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
