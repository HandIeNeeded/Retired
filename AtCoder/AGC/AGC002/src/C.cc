/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 08:22:19 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
int a[N], ans[N], n, L, now;
LL sum[N];

bool solve(int l, int r) {
  if (l == r) return 1;
  if (sum[r] - sum[l - 1] < L) return 0;
  int idx = min_element(a + l, a + r + 1) - a;
  if (idx == l) {
    ans[now++] = l;
    return solve(l + 1, r);
  }
  else if (idx == r) {
    ans[now++] = r - 1;
    return solve(l, r - 1);
  }
  else {
    if (max(sum[idx] - sum[l - 1], sum[r] - sum[idx - 1]) < L) return 0;
    else if (sum[idx] - sum[l - 1] >= L) {
      ans[now++] = idx;
      ans[now++] = idx - 1;
      return solve(l, idx - 1) && solve(idx + 1, r);
    }
    else {
      ans[now++] = idx - 1;
      ans[now++] = idx;
      return solve(l, idx - 1) && solve(idx + 1, r);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> L;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  if (solve(1, n)) {
    cout << "Possible" << endl;
    for (int i = 0; i < n - 1; i++) {
      cout << ans[i] << endl;
    }
  }
  else {
    cout << "Impossible" << endl;
  }

  return 0;
}
