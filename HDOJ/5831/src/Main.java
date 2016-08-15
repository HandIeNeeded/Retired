/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 13 Aug 2016 02:14:09 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;

public class Main {
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int t = in.nextInt();
      for (int i = 0; i < t; i++) {
        int tmp = in.nextInt();
        String s = in.next();
        if ((s.length() & 1) != 0) out.println("No");
        else if (s.length() == 2) {
          if (s.equals(new String(")("))) out.println("Yes");
          else out.println("No");
        }
        else {
          int now = 0, mi = s.length() + 1;
          int x = s.lastIndexOf('('), y = s.indexOf(')');
          for (int j = 0; j < s.length(); j++) {
            if (j == x) now--;
            else if (j == y) now++;
            else if (s.charAt(j) == '(') now++;
            else now--;
            mi = Math.min(mi, now);
          }
          //out.println(now + " " + mi);
          if (now != 0 || mi < 0) out.println("No");
          else out.println("Yes");
        }
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
