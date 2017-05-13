/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri May 12 00:48:14 2017
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

constexpr int N = 2e5 + 5;
int P[N], A[N], B[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> P[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> B[i];
  }
  std::set<int> cnt[4];
  for (int i = 0; i < n; ++i) {
    cnt[A[i]].insert(P[i]);
    cnt[B[i]].insert(P[i]);
  }
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int c;
    std::cin >> c;
    if (cnt[c].size()) {
      std::cout << *cnt[c].begin() << std::endl;
      int price = *cnt[c].begin();
      for (int i = 0; i < 4; ++i) cnt[i].erase(price);
    } else {
      std::cout << -1 << std::endl;
    }
  }

  return 0;
}
