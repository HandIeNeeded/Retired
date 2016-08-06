/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 06 Aug 2016 07:38:47 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int a[555][555];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    int x = i, y = 0;
    int res = 0;
    for (int j = 0; j < n; j++) {
      res += a[x][y];
      x++, y++;
      if (x == n) x = 0;
      if (y == n) y = 0;
    }
    ans = max(ans, res);
  }
  cout << ans << endl;

  return 0;
}
