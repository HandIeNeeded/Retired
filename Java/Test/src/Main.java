/*************************************************************************
  >         File: Main.java
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 25 Sep 2016 12:21:21 AM CST
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

  static class TestString {
    String a;

    public TestString (String s) {
      a = s.toString();
    }

    //public String toString() {
    //  return a;
    //}
  }

  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      Integer a = 10;
      Integer b = a;
      b++;
      out.println(b + " " + a);
      TestString A = new TestString("hehe");
      TestString B = A;
      out.println(A + " " + B);
      B.a = new String("fuck");
      out.println(A + " " + B);
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
