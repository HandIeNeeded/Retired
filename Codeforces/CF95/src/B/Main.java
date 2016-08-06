/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 04 Aug 2016 10:36:15 PM CST
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
      char[] n = new char[100006], ans = new char[100006];
      n = in.next().toCharArray();
      int cnt = (n.length + 1) / 2;
      if ((n.length & 1) != 0) {
        for (int i = 0; i < cnt; i++) {
          ans[i] = '4';
        }
        for (int i = 0; i < cnt; i++) {
          ans[i + cnt] = '7';
        }
      }
      else {
        for (int i = 0; i < cnt; i++) {
          ans[i] = '7';
        }
        for (int i = 0; i < cnt; i++) {
          ans[i + cnt] = '4';
        }
        boolean good = true;
        for (int i = 0; i < n.length; i++) {
          if (ans[i] > n[i]) break;
          if (ans[i] < n[i]) {
            good = false;
          }
        }
        if (good) {
          int a = 0, b = 0;
          for (int i = 0; i < n; i++) {
            if (n[i] != '4' && n[i] != '7') {


              break;
            }
            else {

            }
          }
        }
        else {
          cnt++;
          for (int i = 0; i < cnt; i++) {
            ans[i] = '7';
          }
          for (int i = 0; i < cnt; i++) {
            ans[i + cnt] = '4';
          }
        }
      }
      for (int i = 0; i < 2 * cnt; i++) {
        out.print(ans[i]);
      }
      out.println();
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
