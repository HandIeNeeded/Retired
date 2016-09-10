/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 02:21:29 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 5e4 + 5;
const int M = 1000005;
const int K = 230;
int answer[N];
int A[N], B[N], L, R;
int C[M], D[M];

inline int get(int x) {
  return x / K;
}

class Query {
public:
  int l, r, id;
  Query(int a = 0, int b = 0, int c = 0) :l(a), r(b), id(c) {};

  bool operator < (const Query& rhs) const {
    return get(l) < get(rhs.l) || (get(l) == get(rhs.l) && r < rhs.r);
  }
};

Query q[N];
int sum;

void update(int idx, int value, int type) {
  int pre = std::min(C[idx], D[idx]);
  if (type == 0) C[idx] += value;
  else D[idx] += value;
  int now = std::min(C[idx], D[idx]);
  sum += now - pre;
}

int query(int l, int r) {
  if (get(l) != get(L)) {
    for (int i = 0; i < M; ++i) C[i] = D[i] = 0;
    sum = 0;
    L = 2 * N, R = -2 * N;
  }
  int bound = (get(l) + 1) * K;
  for (int i = std::max(R + 1, bound); i <= r; i++) {
    update(A[i], 1, 0);
    update(B[i], 1, 1);
  }
  for (int i = l; i <= std::min(r, bound - 1); i++) {
    update(A[i], 1, 0);
    update(B[i], 1, 1);
  }
  int ans = sum;
  L = l, R = r;
  for (int i = l; i <= std::min(r, bound - 1); i++) {
    update(A[i], -1, 0);
    update(B[i], -1, 1);
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> B[i];
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    q[i] = Query(l, r, i);
  }
  std::sort(q, q + m);
  L = 2 * N, R = -2 * N;
  for (int i = 0; i < m; ++i) {
    answer[q[i].id] = query(q[i].l, q[i].r);
  }
  std::copy(answer, answer + m, std::ostream_iterator<int>(std::cout, "\n"));
  return 0;
}
