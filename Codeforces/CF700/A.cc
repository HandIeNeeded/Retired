/*************************************************************************
  > File Name: A.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Sat 23 Jul 2016 12:44:56 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

double calc(int A, int B, int a, int b) {
  return (1.0 * b * B - 1.0 * A * a) / (a + b);
}

int main() {
  ios::sync_with_stdio(0);
  
  int n, l, a, b, k;
  cin >> n >> l >> a >> b >> k;
  int cnt = (n + k - 1) / k;
  double ans = 0, pre = 0, d = l;
  for (int i = 0; i < cnt - 1; i++) {
    d = calc(l + pre, l, a, b);
    cout << d << endl;
    pre = d;
  }
  ans = 1.0 * (l - d) / a + 1.0 * d / b;
  cout << fixed << setprecision(10) << ans << endl;


  return 0;
}
