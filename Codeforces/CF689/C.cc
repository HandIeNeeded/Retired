/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 08 Jul 2016 03:29:31 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  LL m;
  cin >> m;
  LL lo = 0, hi = 1e16;
  while (lo + 1 < hi) {
    LL mid = (lo + hi) >> 1;
    int rt = pow(1.0 * mid, 1 / 3);
    while (1LL * (rt + 1) * (rt + 1) * (rt + 1) <= mid) rt++;
    LL ans = 0;
    REPP(i, 2, rt) {
      ans += mid / (1LL * i * i * i);
    }
    //cout << mid << ' ' << rt << ' ' << ans << ' ' << m << endl;
    if (ans >= m) hi = mid;
    else lo = mid;
  }
  int rt = pow(1.0 * hi, 1 / 3);
  while (1LL * (rt + 1) * (rt + 1) * (rt + 1) <= hi) rt++;
  LL ans = 0;
  REPP(i, 2, rt) {
    ans += hi / (1LL * i * i * i);
  }
  if (ans == m) {
    cout << hi << endl;
  }
  else {
    cout << "-1" << endl;
  }

  return 0;
}


