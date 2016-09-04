#include <bits/stdc++.h>

template<int total_size, int char_size, class value_type>
class Automation {
private:
  struct Node {
    std::bitset<char_size> exist;
    Node* son[char_size];
    Node* failptr;
    value_type value;
    Node() {
      exist.reset();
      std::fill(son, son + char_size, nullptr);
      failptr = nullptr; value = 0;
    }
  };
  Node *rt, *ptr, pool[total_size];

  Node* GetNode() {
    return new (ptr++) Node();
  }

  static inline int Index(char c) { 
    return c - 'a'; 
  };

public:
  void Init() {
    ptr = pool;
    rt = GetNode();
  }

  bool Insert(const std::string& str, value_type v = 1) {
    Node* now = rt;
    bool has = true;
    for (auto c: str) {
      int x = Index(c);
      if (!now->exist.test(x)) {
        has = false;
        now->son[x] = GetNode();
        now->exist.set(x);
      }
      now = now->son[x];
    }
    now->value += v;
    return has;
  }

  value_type Find(const std::string& str) {
    Node* now = rt;
    value_type answer = 0;
    for (auto c: str) {
      int x = Index(c);
      now = now->son[x];
      answer += now->value;
    }
    return answer;
  }

  void Build() {
    std::queue<Node*> q;
    for (int i = 0; i < char_size; i++) {
      if (rt->exist.test(i)) {
        rt->son[i]->failptr = nullptr;
        q.emplace(rt->son[i]);
      }
    }
    while (!q.empty()) {
      auto node = q.front(); q.pop();
      for (int i = 0; i < char_size; i++) {
        auto &next = node->son[i];
        if (!node->exist.test(i)) {
          next = node->failptr->son[i];
          continue;
        }
        next->failptr = node->failptr->son[i];
        next->value += next->failptr->value;
        q.emplace(next);
      }
    }
  }
};

int main() {
  Automation<100000, 26, int> ac;
  ac.Init();
  return 0;
}
