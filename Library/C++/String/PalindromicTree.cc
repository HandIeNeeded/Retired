template<int total_size, int char_size, class value_type>
class PT {
private:
  struct Node {
    using NodePtr = Node*;
    NodePtr son[char_size], suffix;
    int length;
    value_type value;
    Node (int l = 0) : suffix(nullptr), length(l), value(0) {
      std::fill(son, son + char_size, nullptr);
    }
  };
  using NodePtr = Node*;
  Node pool[total_size];
  NodePtr ptr, last, odd, even;
  int idx, cnt;
  char s[total_size];

  NodePtr GetNode(int l = 0) {
    return new (ptr++) Node(l);
  }

  inline NodePtr Get(NodePtr p) {
    while (idx -  p->length - 2 < 0 || s[idx - p->length - 2] != s[idx - 1]) p = p->suffix;
    return p;
  }

public:
  void Init() {
    ptr = pool; odd = GetNode(); even = GetNode();
    odd->suffix = even->suffix = odd;
    odd->length = 1; idx = 0, cnt = 2;
  }

  inline int Index(char c) {
    return c - 'a';
  }

  bool Add(char c) {
    int x = Index(c); s[idx++] = c;
    NodePtr p = Get(last);
    if (p->son[x] == nullptr) {
      last = GetNode(p->length + 2);
      if (last->length == 1) {
        last->suffix = even;
      } else {
        last->suffix = Get(p->suffix)->son[x];
      }
      p->son[x] = last;
      return true;
    } else {
      last = p->son[x];
      return false;
    }
  }
};
