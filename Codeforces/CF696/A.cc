/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 14 Jul 2016 11:29:56 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  map<LL, LL> cost;
  int q; 
  cin >> q;
  while (q--) {
    LL x, y;
    int type, value;
    cin >> type >> x >> y;
    if (type == 1) cin >> value;
    vector<LL> A, B;
    while (x) {
      A.push_back(x);
      x >>= 1;
    }
    while (y) {
      B.push_back(y);
      y >>= 1;
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int now = 0;
    while (now + 1 < A.size() && now + 1 < B.size() && A[now + 1] == B[now + 1]) now++;
    if (type == 1) {
      int tmp = now;
      while (tmp + 1 < A.size()) cost[A[++tmp]] += value;
      tmp = now;
      while (tmp + 1 < B.size()) cost[B[++tmp]] += value;
    }
    else {
      LL ans = 0;
      int tmp = now;
      while (tmp + 1 < A.size()) ans += cost[A[++tmp]];
      tmp = now;
      while (tmp + 1 < B.size()) ans += cost[B[++tmp]];
      cout << ans << endl;
    }
  }
  return 0;
}


