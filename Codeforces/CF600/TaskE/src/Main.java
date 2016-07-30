/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 30 Jul 2016 04:10:08 PM CST
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
    TreeMap<Long, Long>[] cnt, sum;
    ArrayList<Integer>[] edges;
    long[] answer;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      HashMap<Integer, Integer> test = new HashMap<>();
      int n = in.nextInt();
      edges = new ArrayList[n + 1];
      cnt = new TreeMap[n + 1];
      sum = new TreeMap[n + 1];
      answer = new long[n + 1];
      for (int i = 1; i <= n; i++) {
        edges[i] = new ArrayList<>();
        cnt[i] = new TreeMap<>();
        sum[i] = new TreeMap<>();
      }
      for (int i = 1; i <= n; i++) {
        long x = in.nextInt();
        cnt[i].put(x, 1L);
        sum[i].put(1L, x);
      }
      for (int i = 1; i <= n - 1; i++) {
        int x = in.nextInt(), y = in.nextInt();
        edges[x].add(y);
        edges[y].add(x);
      }
      dfs(1, 0);
      for (int i = 1; i <= n; i++) {
        out.print(answer[i] + " ");
      }
      out.println();
    }

    private void merge(int a, int b) {
      if (cnt[a].size() < cnt[b].size()) {
        cnt[0] = cnt[a];
        cnt[a] = cnt[b];
        cnt[b] = cnt[0];
        sum[0] = sum[a];
        sum[a] = sum[b];
        sum[b] = sum[0];
      }

      for (Map.Entry<Long, Long> entry : cnt[b].entrySet()) {
        long color = entry.getKey();
        long number = entry.getValue();

        Long tmp = cnt[a].get(color);
        if (tmp != null) {
          long preSum = sum[a].get(tmp);
          sum[a].put(tmp, preSum - color);
          Long now = sum[a].get(tmp + number);
          preSum = now == null ? 0 : now;
          sum[a].put(tmp + number, preSum + color);
          cnt[a].put(color, tmp + number);
        }
        else {
          Long now = sum[a].get(number);
          long preSum = now == null ? 0 : now;
          sum[a].put(number, preSum + color);
          cnt[a].put(color, number);
        }
      }
    }

    private void dfs(int x, int p) {
      for (int y: edges[x]) if (y != p) {
        dfs(y, x);
        merge(x, y);
      }
      answer[x] = sum[x].lastEntry().getValue();
    }
  }

  static final class Pair {
    public int first;
    public int second;

    public Pair(int x, int y) {
      first = x;
      second = y;
    }

    int compareTo(Pair rhs) {
      if (first != rhs.first) return first - rhs.first;
      return second - rhs.second;
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
      return Integer.parseInt(next());
    }
  }
}
