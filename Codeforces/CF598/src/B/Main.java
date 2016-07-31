/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 10:23:42 AM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      String s = in.next();
      char[] str = s.toCharArray();
      int q = in.nextInt();
      while (q-- > 0) {
        int l = in.nextInt();
        int r = in.nextInt();
        int k = in.nextInt();
        k %= (r - l + 1);
        if (k != 0) {
          reverse(str, r - k + 1, r);
          reverse(str, l, r - k);
          reverse(str, l, r);
        }
      }
      out.println(str);
    }

    private void reverse(char[] str, int l, int r) {
      l--; r--;
      for (int i = l, j = r; i < j; i++, j--) {
        char tmp  = str[i];
        str[i] = str[j];
        str[j] = tmp;
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

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }
  }
}
