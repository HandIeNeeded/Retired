import java.lang.Object;
import javafx.util.Pair;

/**
 * Created by yuzhou627 on 7/14/16.
 */
public class TreapSolver {
  class Node {
    int value, size;
    Node left, right;

    Node Update() {
      size = left.size + 1 + right.size;
      return this;
    }
  }

  static int N = 100005;

  Node[] bar, root;

  void Init() {
    bar = new Node[N << 4];
    root = new Node[N << 2];
  }

  boolean Gen(int a, int b) {
    return Math.random() % (a + b) < a;
  }

  Node Merge(Node a, Node b) {
    if (a == null) return b;
    if (b == null) return a;
    if (Gen(a.size, b.size)) {
      a.right = Merge(a.right, b);
      return a.Update();
    }
    else {
      b.left = Merge(a, b.left);
      return b.Update();
    }
  }

  Pair<Node, Node> Split(Node a, int s) {
    //if (a == null) return Pair((Node) null, (Node) null);

  }


}
