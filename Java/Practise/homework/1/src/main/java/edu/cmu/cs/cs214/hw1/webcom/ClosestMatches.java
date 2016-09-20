
package webcom;

import java.io.IOException;

/**
 * class ClosestMathes has the main method to calculate the closest match for each website
 * it calculates the cosine similarity between each pair of websites
 * @author Menglan Wu
 *
 */
public class ClosestMatches {
  /**
 * main method to calculate the closest match for each website and print out N pairs, each pair in a line.
 * @param args urlstrings for several websites
 * @throws IOException ioexceptions
 */
  public static void main(String[] args) throws IOException {
    int[][] flag = new int[args.length][args.length];
    for (int i = 0; i < args.length; i++) {
      for (int j = 0; j < args.length; j++) {
        flag[i][j] = 0;
      }
    }

    double[][] cosSimi = new double[args.length][args.length];

    for (int i = 0; i < args.length; i++) {
      for (int j = 0; j < args.length; j++) {
        Document web1 = new Document(args[i]);
        Document web2 = new Document(args[j]);
        if (i == j) {
          cosSimi[i][j] = 0;
        } else {
          if (i <= j) {
            cosSimi[i][j] = web1.calcusimi(web2);
          } else {
            cosSimi[i][j] = cosSimi[j][i];
          }
        }
      }
    }
    for (int i = 0; i < args.length; i++) {
      Document web11 = new Document(args[i]);
      double biggest = 0;
      int number = 0;
      for (int j = 0; j < args.length; j++) {
        if (flag[i][j] == 1) {
          number = j;
          break;
        } else {
          if (cosSimi[i][j] > biggest) {
            biggest = cosSimi[i][j];
            number = j;
          }
        }
      }
      flag[number][i] = 1;
      Document web22 = new Document(args[number]);
      System.out.println(web11 + " " + web22);
    }

  }

}
