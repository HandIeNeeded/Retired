/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 29 Jul 2016 11:44:13 PM CST
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

  static class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt(), m = in.nextInt();
      int[] A = new int[n + 5], B = new int[m + 5];
      for (int i = 1; i <= n; i++) {
        A[i] = in.nextInt();
      }
      for (int i = 1; i <= m; i++) {
        B[i] = in.nextInt();
      }
      Arrays.sort(A, 1, n + 1);
      Arrays.sort(B, 1, m + 1);
      int answer = Integer.MIN_VALUE;
      for (int i = 1; i <= n; i++) {
        int index = Arrays.binarySearch(B, 1, m + 1, A[i]);
        if (index < 0) {
          index = -(index + 1);
        }
        int tmp = Integer.MAX_VALUE;
        if (index <= m) {
          tmp = Math.min(tmp, B[index] - A[i]);
        }
        if (index - 1 >= 1) {
          tmp = Math.min(tmp, A[i] - B[index - 1]);
        }
        answer = Math.max(answer, tmp);
      }
      out.println(answer);
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
