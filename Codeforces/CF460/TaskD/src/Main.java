/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 29 Jul 2016 03:18:11 PM CST
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
      long l, r, k;
      l = in.nextInt();
      r = in.nextInt();
      k = in.nextInt();
      long result = Long.MAX_VALUE;
      ArrayList<Long> numbers = new ArrayList<>();
      if (r - l + 1 >= 5 && k >= 4) {
        long nl = l;
        if (nl % 2 != 0) {
          nl++;
        }
        long tmp = 0;
        ArrayList<Long> tmpArray = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
          tmpArray.add(nl + i);
        }
        if (tmp < result) {
          result = tmp;
          numbers = tmpArray;
        }
      }
      if (r - l + 1 <= 4 && k <= 4) {
        int cnt = (int) (r - l + 1);
        for (int i = 1; i < (1 << cnt); i++) {
          if (Integer.bitCount(i) > k) continue;
          long tmp = 0;
          ArrayList<Long> tmpArray = new ArrayList<>();
          for (int j = 0; j < cnt; j++) {
            if ((i & (1 << j)) != 0) {
              tmp ^= (l + j);
              tmpArray.add(l + j);
            }
          }
          if (tmp < result) {
            result = tmp;
            numbers = tmpArray;
          }
        }
      }
      if (k >= 1) {
        long tmp = l;
        ArrayList<Long> tmpArray = new ArrayList<>();
        tmpArray.add(l);
        if (tmp < result) {
          result = tmp;
          numbers = tmpArray;
        }
      }
      if (k >= 2) {
        if (r > l + 1) {
          long nl = l;
          if (nl % 2 != 0) {
            nl++;
          }
          long tmp = 1;
          ArrayList<Long> tmpArray = new ArrayList<>();
          tmpArray.add(nl); tmpArray.add(nl + 1);
          if (tmp < result) {
            result = tmp;
            numbers = tmpArray;
          }
        }
        else {
          long tmp = l ^ r;
          ArrayList<Long> tmpArray = new ArrayList<>();
          tmpArray.add(l); tmpArray.add(r);
          if (tmp < result) {
            result = tmp;
            numbers = tmpArray;
          }
        }
      }
      if (k >= 3) {
        //out.println(Long.toBinaryString(r) + " " + Long.toBinaryString(l));
        long A = Long.highestOneBit(l);
        long B = A << 1;
        //2 large 1 small
        if (r >= B + A) {
          result = 0;
          numbers.clear();
          numbers.add(l); numbers.add(B + A); numbers.add(B + l - A);
        }
      }
      out.println(result);
      out.println(numbers.size());
      for (Long x: numbers) {
        out.print(x + " ");
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

    public long nextInt() {
      return Long.parseLong(next());
    }
  }
}
