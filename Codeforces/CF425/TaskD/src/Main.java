/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 30 Jul 2016 09:10:15 PM CST
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
    static final int N = 123457;
    
    private int hashCode(int x, int y) {
      return x * N + y;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      HashSet<Integer> mp = new HashSet<>();
      ArrayList<Integer>[] points = new ArrayList[100001];
      for (int i = 0; i < 100001; i++) {
        points[i] = new ArrayList<>();
      }
      for (int i = 0; i < n; i++) {
        int x = in.nextInt(), y = in.nextInt();
        points[x].add(y);
        mp.add(hashCode(x, y));
      }
      int sqrt = 320;
      long answer = 0;
      for (int i = 0; i < 100001; i++) {
        Collections.sort(points[i]);
      }
      for (int i = 0; i < 100001; i++) {
        if (points[i].isEmpty()) continue;
        if (points[i].size() <= sqrt) {
          for (int a = 0; a < points[i].size(); a++) {
            for (int b = a + 1; b < points[i].size(); b++) {
              int distance = points[i].get(b) - points[i].get(a);
              int hash1 = hashCode(i - distance, points[i].get(a));
              int hash2 = hashCode(i - distance, points[i].get(b));
              if (mp.contains(hash1) && mp.contains(hash2)) answer++;
              if (i + distance < 100001 && points[i + distance].size() > sqrt) {
                hash1 = hashCode(i + distance, points[i].get(a));
                hash2 = hashCode(i + distance, points[i].get(b));
                if (mp.contains(hash1) && mp.contains(hash2)) answer++;
              }
            }
          }
        }
        else {
          for (int j = i + 1; j < 100001; j++) {
            if (points[j].size() <= sqrt) continue;
            int a = 0, b = 0;
            while (a < points[i].size() && b < points[j].size()) {
              int x = points[i].get(a);
              int y = points[j].get(b);
              if (x == y) {
                a++;
                int distance = j - i;
                int hash1 = hashCode(i, x + distance);
                if (!mp.contains(hash1)) continue;
                int hash2 = hashCode(j, y + distance);
                if (!mp.contains(hash2)) continue;
                answer++;
              }
              else if (x < y) a++;
              else b++;
            }
          }
        }
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

    public long nextLong() {
      return Long.parseLong(next());
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
