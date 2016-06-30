/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 24 Jun 2016 12:54:03 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  LL sum = x;
  int ans = 0;
  REP(i, n) {
    char c;
    cin >> c >> x;
    if (c == '+') sum += x;
    else {
      if (sum >= x) sum -= x;
      else ans++;
    }
  }
  cout << sum << ' ' << ans << endl;


  return 0;
}


