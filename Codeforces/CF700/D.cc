/*************************************************************************
  > File Name: D.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Sat 23 Jul 2016 02:49:40 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
const int K = 333;
int a[N];
LL ans[N];
tuple<int, int, int> q[N];

bool cmp(const tuple<int, int, int>&a, const tuple<int, int, int>&b) {
  int x, y, z, w;
  x = get<0>(a), y = get<1>(a), z = get<0>(b), w = get<1>(b);
  return x / K < z / K || (x / K == z / K && y < w);
}

LL Calc(const vector<pair<int, int>> &num) {
  LL ans = 0;
}

map<int, int> cnt, num;
int L, R;

LL GetAns(int l, int r) {
  int idx = l / K;
  int bound = (idx + 1) * K;
  if (idx != L / K) {
    cnt.clear(), num.clear();
    L = N, R = -N;
  }
  for (int i = max(bound, R + 1); i <= r; i++) {
    int has = cnt[a[i]];
    num[has]--, num[has + 1]++;
    if (num[has] == 0) num.erase(has);
    cnt[a[i]]++;
  }
  for (int i = l; i <= min(r, bound - 1); i++) {
    
  }
  vector<pair<int, int>> tmp;
  for (auto &p: num) {

  }
  for
  L = l, R = r;
}

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    q[i] = make_tuple(x, y, i);
  }
  sort(q, q + m, cmp);
  L = N, R = -N;
  for (int i = 0; i < m; i++) {
    ans[get<2>(q[i])] = GetAns(get<0>(q[i]), get<1>(q[i]));
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
