/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 28 Jul 2016 10:38:22 PM CST
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
    static final int K = 20;
    int[] index, depth;
    int[][] previous, next;
    static int clock = 0;
    ArrayList<Integer>[] edges;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n, q;
      n = in.nextInt();
      q = in.nextInt();

      edges = new ArrayList[n + 1];
      index = new int[n + 1];
      depth = new int[n + 1];
      previous = new int[n + 1][K];
      next = new int[n + 1][K];
      for (int i = 1; i <= n; i++) {
        edges[i] = new ArrayList<>();
      }
      for (int i = 0; i < n - 1; i++) {
        int x, y;
        x = in.nextInt();
        y = in.nextInt();
        edges[x].add(y);
        edges[y].add(x);
      }

      FenwickTreeSolver A, B;
      A = new FenwickTreeSolver(n + 1);
      B = new FenwickTreeSolver(n + 1);

      for (int nextNode: edges[1]) {
        dfs(nextNode, nextNode, 1);
      }
      for (int i = 1; i < K; i++) {
        for (int j = 2; j <= n; j++) {
          previous[j][i] = previous[previous[j][i - 1]][i - 1];
          next[j][i] = next[next[j][i - 1]][i - 1];
        }
      }
      int result = 0;
      while (q-- > 0) {
        int type = in.nextInt();
        if (type == 0) {
          int node, value, distance;
          node = in.nextInt();
          value = in.nextInt();
          distance = in.nextInt();
          //out.println("Type " + type + " query");
          if (node == 1) {
            result += value;
            B.add(distance, value);
            continue;
          }
          if (depth[node] <= distance) {
            result += value;
            if (distance > depth[node]) B.add(distance - depth[node], value);
            else {
              int up = go(node, distance - 1);
              int down = go(node, -distance);
              //out.println("Add A 1");
              A.add(index[up], value);
              A.add(index[down] + 1, -value);
              continue;
            }
            int up = go(node, 2 * depth[node] - distance);
            if (next[up][0] != up) {
              int down = go(node, -distance);
              //out.println("Add A 2");
              A.add(index[next[up][0]], value);
              A.add(index[down] + 1, -value);
            }
          }
          else {
            int up = go(node, distance);
            int down = go(node, -distance);
            A.add(index[up], value);
            A.add(index[down] + 1, -value);
          }
        }
        else {
          int node = in.nextInt();
          //out.println("Type " + type + " query");
          if (node == 1) {
            out.println(result);
            continue;
          }
          int answer = 0;
          //out.println(node + " query " + B.query(n) + "  " + (depth[node] - 1));
          answer += B.query(n) - B.query(depth[node] - 1);
          //out.println(answer);
          answer += A.query(index[node]);
          //out.println("hehe" + answer + " " + A.query(1));
          out.println(answer);
        }
      }
    }

    private int go(int index, int step) {
      if (step < 0) {
        step = -step;
        for (int i = 0; i < K; i++) {
          if (((1 << i) & step) != 0) {
            index = next[index][i];
          }
        }
      }
      else {
        for (int i = 0; i < K; i++) {
          if (((1 << i) & step) != 0) {
            index = previous[index][i];
          }
        }
      }
      return index;
    }

    public void dfs(int node, int p, int dep) {
      index[node] = ++clock;
      depth[node] = dep;
      previous[node][0] = p;
      for (int nextNode: edges[node]) {
        if (nextNode != p && nextNode != 1) {
          dfs(nextNode, node, dep + 1);
          next[node][0] = nextNode;
        }
      }
      if (next[node][0] == 0) next[node][0] = node;
    }
  }

  static class SegmentTreeSolver {
    int[] A, B;

    public SegmentTreeSolver(int n) {
      A = new int[(n * 4) + 5];
      B = new int[(n * 4) + 5];
    }

    public void push(int x, int l, int r) {
      int mid = (r + l) >> 1;
      int L = x << 1, R = x << 1 | 1;
      A[L] += (mid - L + 1) * B[x];
      A[R] += (r - mid) * B[x];
      B[L] += B[x];
      B[R] += B[x];
      B[x] = 0;
    }

    public void update(int x, int l, int r, int ql, int qr, int value) {
      if (ql <= l && qr >= r) {
        A[x] += (r - l + 1) * value;
        B[x] += value;
      }
      else {
        if (B[x] > 0) {
          push(x, l, r);
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) update(x << 1, l, mid, ql, qr, value);
        if (qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr, value);
      }
    }

    public int query(int x, int l, int r, int qx) {
      if (l == r) {
        return A[x];
      }
      else {
        int mid = (l + r) >> 1;
        if (B[x] > 0) {
          push(x, l, r);
        }
        if (qx < mid) return query(x << 1, l, mid, qx);
        else return query(x << 1 | 1, mid + 1, r, qx);
      }
    }
  }

  static class FenwickTreeSolver {
    int[] A;
    public FenwickTreeSolver(int n) {
      A = new int[n + 5];
    }

    private int lowbit(int x) {
      return x & (-x);
    }

    void add(int index, int value) {
      while (index < A.length) {
        A[index] += value;
        index += lowbit(index);
      }
    }

    int query(int index) {
      int answer = 0;
      while (index != 0) {
        answer += A[index];
        index -= lowbit(index);
      }
      return answer;
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
  }
}
