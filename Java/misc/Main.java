/*************************************************************************
  >         File: Main.java
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 19 Sep 2016 08:15:44 AM CST
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

  static class Name {
    private final String first, last;
    public Name (String first, String last) {
      if (first == null || last == null) {
        throw new NullPointerException();
      }
      this.first = first; this.last = last;
    }

    public boolean equals(Object o) {
      if (!(o instanceof Name)) return false;
      if (o == this) return true;
      return first.equals(((Name) o).first) && last.equals(((Name) o).last);
    }

    public int hashCode() {
      return 31 * first.hashCode() + last.hashCode();
    }
  }

  static class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      String a = new String("hehe"), b = new String("hehe");
      out.println(a.hashCode() + " " + b.hashCode());
      Set<String> t = new HashSet<> ();
      t.add(a);
      out.println(t.contains(b));
      Set<Name> s = new HashSet<> ();
      s.add(new Name("Mickey", "Mouse"));
      out.println(s.contains(new Name("Mickey", "Mouse")));
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
