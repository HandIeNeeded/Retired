/*************************************************************************
  > File Name: B.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Sat 16 Jul 2016 08:19:30 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL solve(LL n, LL x) {
  if (n % x == 0) {
    return n + ((n - x) / x * 2 - 1) * x;
  }
  else {
    if (2 * x > n) {
      return solve(n, n - x);
    }
    else {
      LL ans = n + ((n - x) / x * 2 - 1) * x + n % x * 2;
      return ans + solve(x, x - n % x);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  LL n, x;
  cin >> n >> x;
  cout << solve(n, x) << endl;
  return 0;
}
