/**
 * Created by yuzhou627 on 7/13/16.
 */
import java.util.*;

public class AutomationSolver {
  public static int N = 10005, LEN = 10, Z = 26;
  int[][] trie;
  int[] fail;
  int node;

  int Node() {
    trie[node] = new int[Z];
    return node++;
  }

  void Init() {
    node = 0;
    trie = new int[N * LEN][Z];
    fail = new int[N * LEN];
    this.Node();
  }

  int GetIndex(char c) {
    return c - 'a';
  }

  void Insert(String str) {
    int position = 0, now = 0;
    while (position < str.length()) {
      int x = this.GetIndex(str.charAt(position++));
      if (trie[now][x] == 0) {
        trie[now][x] = this.Node();
      }
      now = trie[now][x];
    }
  }

  void GetFailLinks() {
    Queue<Integer> que = new ArrayDeque<>();
    for (int x: trie[0]) if (x != 0) {
      fail[x] = 0;
      que.add(x);
    }
    while (!que.isEmpty()) {
      int node = que.poll();
      for (int i = 0; i < Z; i++) {
        if (trie[node][i] == 0) {
          trie[node][i] = trie[fail[node]][i];
          continue;
        }
        int y = trie[node][i];
        que.add(y);
        fail[y] = trie[fail[node]][i];
      }
    }
  }

  public static void main(String[] args) {
    AutomationSolver tester = new AutomationSolver();
    tester.Init();
    tester.Insert("hello");
    tester.Insert("world");
    tester.GetFailLinks();
  }
}
