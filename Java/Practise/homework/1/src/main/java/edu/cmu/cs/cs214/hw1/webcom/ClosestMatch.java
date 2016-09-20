
package webcom;

import java.io.IOException;

/**
 * 
 * @author Menglan Wu
 *
 */
public class ClosestMatch {
  /** 
   * main method to calculate closest match and print the closest match and its cosine similarity.
   * @param args url Strings
   * @throws IOException ioexceptions
   * 
   */
  public static void main(String[] args) throws IOException {
    double[][] cosSimi = new double[args.length][args.length];

    for (int i = 0; i < args.length; i++) {
      for (int j = 0; j < args.length; j++) {
        Document web1 = new Document(args[i]);
        Document web2 = new Document(args[j]);
        if (i == j) {
          cosSimi[i][j] = 0;
        }
        if (i <= j) {
          cosSimi[i][j] = web1.calcusimi(web2);
        } else {
          cosSimi[i][j] = cosSimi[j][i];
        }
      }
    }

    double biggest = 0;
    int itemp = 0;
    int jtemp = 0;
    for (int i = 0; i < args.length; i++) {
      for (int j = i + 1; j < args.length; j++) {
        if (cosSimi[i][j] > biggest) {
          biggest = cosSimi[i][j];
          itemp = i;
          jtemp = j;
        }
      }
    }
    Document web11 = new Document(args[itemp]);
    Document web22 = new Document(args[jtemp]);
    System.out.println(web11);
    System.out.println(web22);
    System.out.println(cosSimi[itemp][jtemp]);

  }
}
