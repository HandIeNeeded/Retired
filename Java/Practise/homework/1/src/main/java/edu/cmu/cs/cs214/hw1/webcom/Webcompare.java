/**
 *  The Webcompare class is to get a website's html and build a frequency table.
 *  It also calculate the sum of frequency's square.
 *  
 */

package webcom;

import java.io.IOException;
import java.net.URL;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
/**
 * Webcompare is a class contains the main method.
 * @author Menglan Wu
 *
 */
public class Webcompare {
  /**
   * main is a method to print the cosine similarity.
   * @param args url strings for several websites
   * @throws IOException ioexceptions
   * 
   */
  public static void main(String[] args) throws IOException {
    Document webA = new Document(args[0]);
    System.out.println(webA);
    Document webB = new Document(args[1]);
    System.out.println(webB);
    double result;
    result = webA.calcusimi(webB);
    System.out.println(result);
  }
}

/**
 *  Document is a method to construct a map whose key is word and value is its frequency
 *  It also calculate the sum of frequency.
 * @author Menglan Wu
 *
 */
class Document {
  private String urlString;
  private Set<String> words;
  private Map<String, Integer> wordFreq;
  private double sum;

  // constructor
  public Document(String urlString) throws IOException {
    this.urlString = urlString;

    Scanner sc = new Scanner(new URL(urlString).openStream());
    wordFreq = new TreeMap<>();
  
    while (sc.hasNext()) {
      String temp = sc.next();
      if (wordFreq.containsKey(temp)) {
        wordFreq.put(temp, wordFreq.get(temp) + 1);
      } else {
        wordFreq.put(temp, 1);
      }
    }
    sc.close();
    words = wordFreq.keySet();
    sum = 0;
    for (String word : words) {
      sum = sum + wordFreq.get(word) * wordFreq.get(word);
    }
  }

  public double calcusimi(Document second) {
    double inpro = 0;
    for (String compareWord : words) {
      for (String word2 : second.words) {
        if (compareWord.equals(word2)) {
          inpro = inpro + wordFreq.get(compareWord) * (second.wordFreq.get(word2));
        }
      }
    }
    return inpro / (Math.sqrt(sum) * Math.sqrt(second.sum));
  }

  @Override public String toString() {
    return urlString;
  }

}