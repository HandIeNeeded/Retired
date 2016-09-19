/*************************************************************************
  >         File: P5869.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 19 Sep 2016 09:05:44 PM CST
 *************************************************************************/
#include <bits/stdc++.h>
constexpr int N = 1e5 + 5;
constexpr int M = 1e6 + 6;
std::pair<int, int> queries[N];
int a[N], left[N], cnt[N], previous[M];

void Modify(int x, int d = 1) {
  if (x == 0) return ;
  for (; x < N; x += x & -x) cnt[x] += d;
}

int Ask(int x) {
  int answer = 0;
  for (; x > 0; x -= x & -x) answer += cnt[x];
  return answer;
}

void Update(int position) {
  int gcd = a[position];
  while (position > 0) {
    while (left[position] > 0 && std::__gcd(a[left[position]], gcd) == gcd) {
      left[position] = left[left[position]];
    }
    if (previous[gcd] < position) {
      Modify(previous[gcd], -1);
      Modify(position);
    }
    previous[gcd] = position;
    position = left[position];
    gcd = std::__gcd(gcd, a[position]);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, q;
  while (std::cin >> n >> q) {
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) left[i] = i - 1;
    for (int i = 0; i < q; ++i) {
      int x, y;
      std::cin >> x >> y;
      queries[i] = {x, y};
    }
    std::vector<int> indexs(q, 0), answer(q, 0);
    std::iota(indexs.begin(), indexs.end(), 0);
    std::sort(indexs.begin(), indexs.end(), [] (int a, int b) {
      return queries[a].second < queries[b].second;
    });
    std::fill(previous, previous + M, 0);
    std::fill(cnt, cnt + N, 0);
    int now = 1;
    for (auto &i: indexs) {
      int right = queries[i].second;
      while (now <= right) {
        Update(now++);
      }
      answer[i] = Ask(right) - Ask(queries[i].first - 1);
    }
    std::copy(answer.begin(), answer.end(), std::ostream_iterator<int>(std::cout, "\n"));
  }
  return 0;
}
