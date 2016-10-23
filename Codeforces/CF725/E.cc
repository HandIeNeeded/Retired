/*************************************************************************
  >         File: E.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 23 Oct 2016 12:18:16 AM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 2e5 + 5;
int a[N], cnt[N];
int A[N];

void Add(int x, int d) {
  for (; x < N; x += x & -x) {
    A[x] += d;
  }
}

int Ask(int x) {
  int ans = 0;
  for (; x > 0; x -= x & -x) {
    ans += A[x];
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  int c;
  std::cin >> c;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i], cnt[a[i]]++;
  for (int i = 0; i < N; ++i) if (cnt[i]) Add(i, 1);
  for (int i = 1; i <= c - 1; ++i) {
    if (cnt[i] == 0) Add(i, 1);
    cnt[i]++;
    int now = c;
    int pointer = c;
    while (now) {
      pointer = std::min(pointer, now);
      int count = Ask(pointer);
      if (count == 0) break;
      int lo = 0, hi = pointer;
      while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (Ask(mid) == count) hi = mid;
        else lo = mid;
      }
      int k = std::min(now / hi, cnt[hi]);
      now -= k * hi;
      pointer = hi - 1;
    }
    if (now) {
      std::cout << i << std::endl;
      return 0;
    }
    cnt[i]--;
    if (cnt[i] == 0) Add(i, -1);
  }
  std::cout << "Greed is good" << std::endl;
  return 0;
}
