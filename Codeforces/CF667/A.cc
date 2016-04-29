/*************************************************************************
  > File Name: A.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 30 Apr 2016 01:12:53 AM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const double pi = acos(-1);
int main() {
  ios::sync_with_stdio(0);
  int e, d, v, h;
  cin >> d >> h >> v >> e;
  if (e > 4 * v / (pi * d * d)) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    double speed = 4 * v / (pi * d * d) - e;
    cout << fixed << setprecision(10) << h / speed << endl;
  }



  return 0;
}


