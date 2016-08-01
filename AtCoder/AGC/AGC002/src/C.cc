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
int a[N], n, L;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> L;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mx = 0;
  int idx = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] + a[i + 2] > mx) {
      mx = a[i + 1] + a[i + 2];
      idx = i + 1;
    }
  }
  if (mx < L) {
    cout << "Impossible" << endl;
  }
  else {
    cout << "Possible" << endl;
    for (int i = 1; i < idx; i++) {
      cout << i << endl;
    }
    for (int i = n - 1; i >= idx; i--) {
      cout << i << endl;
    }
  }

  return 0;
}
