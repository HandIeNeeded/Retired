/*************************************************************************
  >         File: P1007.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 01:34:26 PM CST
*************************************************************************/
#include <bits/stdc++.h>
constexpr int N = 1e5 + 5;
int n, k;
int a[N];

bool Huffman(int x) {
  assert(x > 1);
  std::priority_queue<int, std::vector<int>, std::greater<int>> q(a, a + n);
  int sum = k;
  while (q.size() > 1) {
    int ans = 0;
    int cnt = std::min(x, (int) q.size());
    for (int i = 0; i < cnt; ++i) {
      ans += q.top(); q.pop();
    }
    sum -= ans;
    q.emplace(ans);
    if (sum < 0) return false;
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int lo = 1, hi = n;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (Huffman(mid)) hi = mid;
      else lo = mid;
    }
    printf("%d\n", hi);
  }


  return 0;
}
