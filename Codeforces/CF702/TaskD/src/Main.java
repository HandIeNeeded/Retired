/*************************************************************************
  >         File: Main.java
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 30 Jul 2016 12:13:15 AM CST
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
    long distance, stepCar, restCar, timeCar, timePerson;

    private long calc(long x) {
      if (x <= 0) return 0;
      long answer = x / stepCar * (stepCar * timeCar + restCar);
      if (x % stepCar != 0) {
        answer += (x % stepCar) * timeCar;
      }
      else {
        answer -= restCar;
      }
      return answer;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      distance = in.nextInt();
      stepCar = in.nextInt();
      timeCar = in.nextInt();
      timePerson = in.nextInt();
      restCar = in.nextInt();
      long answer = Math.min(distance * timePerson, calc(distance));
      for (int i = 1; i <= Math.min(2 * stepCar, distance); i++) {
        long result = i * timePerson + calc(distance - i);
        answer = Math.min(answer, result);
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

    public Long nextInt() {
      return Long.parseLong(next());
    }

  }
}
