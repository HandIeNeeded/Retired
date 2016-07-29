/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 28 Jul 2016 07:01:51 PM CST
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
      int n = in.nextInt();
      int[] value = new int[n + 1];
      int[] sum = new int[2];
      ArrayList<Integer>[] A = new ArrayList[2];
      for (int i = 0; i < 2; i++) {
        A[i] = new ArrayList<>(n);
      }
      for (int i = 0; i < n; i++) {
        int color;
        color = in.nextInt();
        value[i + 1] = in.nextInt();
        A[color].add(i + 1);
        sum[color] += value[i + 1];
      }
      assert sum[0] == sum[1];

      int[][] answer = new int[n - 1][3];

      for (int i = 0; i < n - 1; i++) {
        answer[i] = new int[3];
      }
      int[] index = new int[2];
      int now = 0, cnt = 0;
      while (index[0] < A[0].size() && index[1] < A[1].size()) {
        int node = A[now].get(index[now]);
        int next = now ^ 1;
        while (index[next] < A[next].size()) {
          int nextNode = A[next].get(index[next]);
          if (value[nextNode] > value[node]) break;
          answer[cnt][0] = node;
          answer[cnt][1] = nextNode;
          answer[cnt++][2] = value[nextNode];
          value[node] -= value[nextNode];
          index[next]++;
        }
        if (index[next] == A[next].size()) break;
        else {
          answer[cnt][0] = node;
          answer[cnt][1] = A[next].get(index[next]);
          answer[cnt++][2] = value[node];
          value[A[next].get(index[next])] -= value[node];
          index[now]++;
          now = next;
        }
      }
      index[now]++;
      int lastNode = answer[cnt - 1][1];
      while (index[now] < A[now].size()) {
          answer[cnt][0] = A[now].get(index[now]++);
          answer[cnt][1] = lastNode;
          answer[cnt++][2] = 0;
      }
      for (int i = 0; i < n - 1; i++) {
        assert  answer[i][0] >= 1 && answer[i][0] <= n;
        assert  answer[i][1] >= 1 && answer[i][1] <= n;
        out.println(answer[i][0] + " " + answer[i][1] + " " + answer[i][2]);
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
  }
}
