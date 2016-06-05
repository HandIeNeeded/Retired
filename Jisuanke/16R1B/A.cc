/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 05 Jun 2016 01:04:03 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const double pi = acos(-1);

int main() {
  ios::sync_with_stdio(0);
  double a, b, c;
  cin >> a >> b >> c;
  a /= 2.0, b /= 2.0;
  double d = sqrt(a * a + b * b - 2 * a * b * cos(c / 180 * pi));
  d += a + b;
  d = max(d, max(a, b));
  cout << fixed << setprecision(10) << pi * d * d / 4.0 << endl;


  return 0;
}


