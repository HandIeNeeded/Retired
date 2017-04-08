/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  8 21:05:30 2017
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID 
#define RC R, MID + 1, r

constexpr int N = 2e5;

struct Tree {
  std::string s;
  int a[N << 2];

  Tree(std::string s = "") {
    this->s = s;
    build(1, 1, s.size());
  };

  int get(int a, int b) {
    return (a + b) % 3;
  }

  void build(int x, int l, int r) {
    if (l > r) return ;
    if (l == r) {
      a[x] = s[l - 1] - 'A' + 1;
    } else {
      build(LC), build(RC);
      a[x] = get(a[L], a[R]);
    }
  }

  int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) return a[x];
    else {
      if (ql > MID) return query(RC, ql, qr);
      if (qr <= MID) return query(LC, ql, qr);
      return get(query(LC, ql, qr), query(RC, ql, qr));
    }
  }
}T[2];

int main() {
  std::ios::sync_with_stdio(0);
  std::string s[2];
  for (int i = 0; i < 2; ++i) std::cin >> s[i], T[i] = Tree(s[i]);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int x = T[0].query(1, 1, s[0].size(), a, b);
    int y = T[1].query(1, 1, s[1].size(), c, d);
    x == y ? puts("YES") : puts("NO");
  }

  return 0;
}
