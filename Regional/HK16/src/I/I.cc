/*************************************************************************
  >         File: I.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 01:10:26 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

constexpr int N = 1e5 + 5;
constexpr int C = 26;

struct PT{
  char s[N];
  struct Node{
    Node *ch[C], *suffix;
    int len, dp;
  }bar[N];

  Node *foo, *last, *odd, *even;
  int n, cnt;//cnt = foo - bar = count of palindromes, n the number of char added

  void Init() {
    odd = bar, even = last = odd + 1, foo = even + 1;
    memset(odd->ch, 0, sizeof(odd->ch));
    memset(even->ch, 0, sizeof(even->ch));
    odd->suffix = even->suffix = odd;
    odd->len = -1, even->len = 0;
    odd->dp = even->dp = 0;
    n = 0, cnt = 2;//root
  }

  Node* New(int x) {
    memset(foo->ch, 0, sizeof(foo->ch));
    foo->len = x;
    foo->dp = 0;
    return foo++;
  }

  int Index(char c) {
    return c - 'a';
  }

  Node* Get(Node *p) {
    while (n - p->len - 2 < 0 || s[n - p->len - 2] != s[n - 1]) p = p->suffix;
    return p;
  }

  int Add(char c) {
    int x = Index(c); s[n++] = c;
    Node *p = Get(last);
    if (!p->ch[x]) {
      last = New(p->len + 2);
      if (last->len == 1) {
        last->suffix = even;
      }
      else last->suffix = Get(p->suffix)->ch[x];//guarantee proper suffix
      p->ch[x] = last;
      p->ch[x]->dp = last->suffix->dp + 1;
      cnt++;
    }
    else {
      last = p->ch[x];
    }
    return p->ch[x]->dp;
  }
};

LL prefix[N];
PT solver;

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  std::cout << s << std::endl;
  solver.Init();
  for (int i = 0; i < (int) s.size(); ++i) {
    prefix[i + 1] = prefix[i] + solver.Add(s[i]);
    std::cout << prefix[i + 1] - prefix[i] << std::endl;
  }
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << prefix[r] - prefix[l - 1] << std::endl;
  }
  return 0;
}
