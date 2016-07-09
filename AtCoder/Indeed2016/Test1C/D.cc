/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 09 Jul 2016 07:49:02 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 3e5 + 5;
int prefixMin[N], suffixMin[N], a[N];

int main() {
  ios::sync_with_stdio(0);
  int n;
  string str;
  cin >> n >> str;
  REPP(i, 0, n) {
    cin >> a[i];
  }
  prefixMin[0] = a[0], suffixMin[n] = a[n];
  REPP(i, 1, n) prefixMin[i] = min(prefixMin[i - 1], a[i]);
  for (int i = n - 1; i >= 0; i--) suffixMin[i] = min(suffixMin[i + 1], a[i]);
  int now = 0;
  vector<int> keyPositions;
  LL ans = 0;
  REP(i, n) {
    if (str[i] == '(') {
      now++;
      keyPositions.push_back(i + 1);
    }
    else {
      now--;
      if (now >= 0) keyPositions.pop_back();
      else ans += prefixMin[i], now = 0;
    }
  }
  REP(i, now) {
    ans += suffixMin[keyPositions[i]];
  }
  cout << ans << endl;
  return 0;
}


