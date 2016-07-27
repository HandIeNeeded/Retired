/*************************************************************************
  > File Name: Main.java
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Wed 27 Jul 2016 08:35:10 PM CST
*************************************************************************/

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
      String[] strs = new String[3], usedStrs = new String[3];
      boolean[] mark = new boolean[3];
      for (int i = 0; i < 3; i++) {
        strs[i] = in.next();
      }
      int now = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) if (i != j) {
          KMPSolver solver = new KMPSolver(strs[i]);
          if (solver.find(strs[j])) {
            mark[i] = true;
            if (strs[i].equals(strs[j]) && i < j) {
              mark[i] = false;
            }
          }
        }
      }
      for (int i = 0; i < 3; i++) {
        if (!mark[i]) {
          usedStrs[now++] = strs[i];
        }
      }
      if (now == 1) out.println(usedStrs[0].length());
      else {
        Arrays.sort(usedStrs, 0, now, Comparator.reverseOrder());
        int answer = 0;
        for (int i = 0; i < now; i++) answer += usedStrs[i].length();
        int sum = answer;
        //System.out.println(sum + " " + now);

        while (true) {
          int result = sum;
          for (int i = 0; i < now - 1; i++) {
            KMPSolver solver = new KMPSolver(usedStrs[i + 1]);
            result -= solver.getLcp(usedStrs[i]);
          }
          answer = Math.min(answer, result);
          int position = 0;
          for (int i = 1; i < now; i++) {
            if(usedStrs[i].compareTo(usedStrs[i - 1]) < 0) {
              position = i;
              break;
            }
          }
          if (position == 0) break;
          int key = 0;
          for (int i = 0; i < position; i++) {
            if (usedStrs[i].compareTo(usedStrs[position]) > 0) {
              key = i;
              break;
            }
          }
          String tmp = new String();
          tmp = usedStrs[position];
          usedStrs[position] = usedStrs[key];
          usedStrs[key] = tmp;

          for (int i = 0, j = position - 1; i < j; i++, j--) {
            tmp = usedStrs[i];
            usedStrs[i] = usedStrs[j];
            usedStrs[j] = tmp;
          }
        }
        System.out.println(answer);
      }
    }
  }

  static class KMPSolver {
    int[] fail;
    String str;

    public KMPSolver(String a) {
      str = a;
      fail = new int[a.length() + 1];
      fail[0] = fail[1] = 0;
      for (int i = 1; i < a.length(); i++) {
        int j = fail[i];
        while (j != 0 && str.charAt(j) != str.charAt(i)) j = fail[j];
        fail[i + 1] = str.charAt(j) == str.charAt(i) ? j + 1 : 0;
      }
    }

    public boolean find(String a) {
      int position = 0;
      for (int i = 0; i < a.length(); i++) {
        if (position == str.length()) return true;
        if (position < str.length() && a.charAt(i) == str.charAt(position)) position++;
        else {
          int j = fail[position];
          while (j != 0 && a.charAt(i) != str.charAt(j)) j = fail[j];
          position = a.charAt(i) == str.charAt(j) ? j + 1 : 0;
        }
      }
      return false;
    }

    public int getLcp(String a) {
      int position = 0;
      for (int i = 0; i < a.length(); i++) {
        if (position < str.length() && a.charAt(i) == str.charAt(position)) position++;
        else {
          int j = fail[position];
          while (j != 0 && a.charAt(i) != str.charAt(j)) j = fail[j];
          position = a.charAt(i) == str.charAt(j) ? j + 1 : 0;
        }
      }
      return position;
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

