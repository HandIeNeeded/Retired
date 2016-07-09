/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 07:06:32 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  LL lo = 0, hi = 1e11;
  a <<= 1, b <<= 1;
  while (lo + 1 < hi) {
    LL mid = (lo + hi) >> 1;
    LL tot = mid / a + (mid - 1) / b;
    if (tot >= k) hi = mid;
    else lo = mid;
  }
  if (hi % a == 0) {
    cout << "Takahashi" << endl;
  }
  else {
    cout << "Aoki" << endl;
  }

  return 0;
}


