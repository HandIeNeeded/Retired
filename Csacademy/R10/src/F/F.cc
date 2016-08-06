/*************************************************************************
  >         File: F.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 06 Aug 2016 08:06:46 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
typedef long double ld;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  ld ans = 0;
  ld sum = 0, sqrSum = 0.0;
  for (int i = 1; i <= n - 1; i++) {
    sum += 1.0 / i;
    sqrSum += 1.0 / (1LL * i * i);
  }
  ans += sum * sum + sum - sqrSum;
  sum += 1.0;
  sqrSum += 1.0;
  for (int i = 2; i <= n; i++) {
    sum -= 1.0 / (i - 1);
    sqrSum -= 1.0 / (1LL * (i - 1) * (i - 1));
    ans += sum * sum - sqrSum + sum;
  }
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
