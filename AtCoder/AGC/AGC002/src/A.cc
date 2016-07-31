/*************************************************************************
  >         File: A.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 08:00:23 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  int has = 0;
  if (a <= 0 && b >= 0) has = 1;
  if (has) {
    cout << "Zero" << endl;
  }
  else {
    if (a > 0) {
      cout << "Positive" << endl;
    }
    else {
      int cnt = 0;
      if (b < 0) {
        cnt = (b - a + 1);
      }
      else {
        cnt = -a;
      }
      cout << ((cnt & 1) ? "Negative" : "Positive") << endl;
    }
  }

  return 0;
}
