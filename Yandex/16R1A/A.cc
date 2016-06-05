/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 08:59:40 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int p, a, b;
  cin >> p >> a >> b;
  if (p < b) {
    cout << -1 << endl;
    return 0;
  }
  cout << max(p, a + b) << endl;
  return 0;
}


