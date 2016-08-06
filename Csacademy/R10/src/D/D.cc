/*************************************************************************
  >         File: D.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 06 Aug 2016 07:43:53 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int a[10005];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    ans += 1LL * (i + 1) * (i + 1) * a[i];
    int sum = 0;
    for (int k = 1; k < n; k++) {
      int l = i - k, r = i + k;
      if (l < 0 || r == n) break;
      if (a[l] > a[i]) sum++;
      if (a[l] < a[i]) sum--;
      if (a[r] > a[i]) sum++;
      if (a[r] < a[i]) sum--;
      if (sum == 0) {
        ans += 1LL * (l + 1) * (r + 1) * a[i];
      }
    }
  }
  cout << ans << endl;


  return 0;
}
