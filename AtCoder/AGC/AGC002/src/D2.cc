/*************************************************************************
  >         File: D2.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 02 Sep 2016 08:03:44 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
int A[N], B[N];
int f[N], cnt[N], edge;
int n, m, q, C[N], D[N], E[N];

int Get(int x) {
  return f[x] == x ? x : f[x] = Get(f[x]);
}

void Merge(int x, int y) {
  edge++;
  int tx = Get(x), ty = Get(y);
  if (tx != ty) {
    cnt[tx] += cnt[ty];
    f[ty] = tx;
  }
}

void Init(int n) {
  edge = 0;
  std::iota(f + 1, f + n + 1, 1);
  std::fill(cnt + 1, cnt + n + 1, 1);
}

std::vector<int> answer;

template<class T>
void Solve(T first, T last) {
  if (first == last) return ;
  std::queue<std::tuple<int, int, T, T>> q;
  q.emplace(0, m, first, last);
  while (!q.empty()) {
    T begin, end;
    int x, y;
    std::tie(x, y, begin, end) = q.front(); q.pop();
    if (begin == end) continue;
    if (y - 1 == x) {
      for (auto itr = begin; itr != end; itr++) {
        answer[*itr - 1] = y;
      }
      continue;
    }
    int mid = x + (y - x) / 2;
    if (edge > mid) {
      Init(n);
      for (int i = 0; i < mid; i++) {
        Merge(A[i + 1], B[i + 1]);
      }
    } else {
      for (int i = edge; i < mid; i++) {
        Merge(A[i + 1], B[i + 1]);
      }
    }
    auto bound = std::partition(begin, end, [] (auto idx) {
      int a = Get(C[idx]), b = Get(D[idx]);
      int total = a == b ? cnt[a] : cnt[a] + cnt[b];
      return total >= E[idx];
    });
    q.emplace(x, mid, begin, bound);
    q.emplace(mid, y, bound, end);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d", A + i + 1, B + i + 1);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) scanf("%d%d%d", C + i + 1, D + i + 1, E + i + 1);
  std::vector<int> idx(q);
  answer.assign(q, 0);
  std::iota(idx.begin(), idx.end(), 1);
  Init(n);
  Solve(idx.begin(), idx.end());
  for (auto &x: answer) {
    printf("%d\n", x);
  }
  return 0;
}
