/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 02:24:56 PM CST
*************************************************************************/
import java.io.*;
import java.util.*;
import java.math.*;

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
    Point[] p;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt();
      p = new Point[n];
      for (int i = 0; i < n; i++) {
        int x = in.nextInt(); 
        int y = in.nextInt();
        p[i] = new Point(x, y, i + 1);
      }
      Arrays.sort(p, new Comparator<Point> () {
        public int compare(Point lhs, Point rhs) {
          if (lhs.dim() == rhs.dim()) {
            return Point.det(lhs, rhs) < 0 ? 1 : -1;
          }
          else {
            return lhs.dim() < rhs.dim() ? 1 : -1;
          }
        }
      });
      BigDecimal ans = new BigDecimal("-100.0");
      int best = -1;
      for (int i = 0; i < n; i++) {
        BigDecimal angle = calc(i, (i + 1) % n);
        if (angle.compareTo(ans) > 0) {
          best = i;
          ans = angle;
        }
      }
      //out.println(ans);
      out.println(p[best].idx + " " + p[(best + 1) % n].idx);
    }

    private BigDecimal sqrt(BigDecimal x, final int scale) {
      BigDecimal x0 = new BigDecimal("0");
      BigDecimal x1 = new BigDecimal(Math.sqrt(x.doubleValue()));
      while (!x0.equals(x1)) {
        x0 = x1;
        x1 = x.divide(x0, scale, BigDecimal.ROUND_HALF_UP);
        x1 = x1.add(x0);
        x1 = x1.divide(new BigDecimal("2"), scale, BigDecimal.ROUND_HALF_UP);
      }
      return x1;
    }

    private BigDecimal calc(int x, int y) {
      Point np = new Point(p[x].x - p[y].x, p[x].y - p[y].y, 0);
      BigDecimal up = new BigDecimal(p[x].norm() + p[y].norm() - np.norm());
      BigDecimal down = new BigDecimal("2");
      down = down.multiply(sqrt(new BigDecimal(p[x].norm()), 50));
      down = down.multiply(sqrt(new BigDecimal(p[y].norm()), 50));
      return up.divide(down, 50, BigDecimal.ROUND_HALF_UP);
    }
  }

  static final class Point implements Comparator<Point> {
    public long x, y;
    public int idx;

    public Point(long a, long b, int c) {
      x = a; y = b;
      idx = c;
    }

    public long norm() {
      return x * x + y * y;
    }

    public int dim() {
      return x < 0 || (x == 0 && y < 0) ? 1 : 0;
    }

    public int compare(Point lhs, Point rhs) {
      if (lhs.dim() == rhs.dim()) {
        return det(lhs, rhs) < 0 ? 1 : -1;
      }
      else {
        return lhs.dim() < rhs.dim() ? 1 : -1;
      }
    }

    static long det(Point a, Point b) {
      return a.x * b.y - a.y * b.x;
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
