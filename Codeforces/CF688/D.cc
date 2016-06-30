/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 30 Jun 2016 01:43:29 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 1006;
int tot, p[N], vis[N];
void prime() {
  for (int i = 2; i < N; i++) {
    if (!vis[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  prime();
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> factors;
  for (int i = 0; i < tot && p[i] * p[i] <= k; i++) {
    if (k % p[i] == 0) {
      int cnt = 0;
      while (k % p[i] == 0) {
        cnt++;
        k /= p[i];
      }
      factors.push_back({p[i], cnt});
    }
  }
  if (k > 1) {
    factors.push_back({k, 1});
  }
  REP(i, n) {
    int x;
    cin >> x;
    for (int i = 0; i < factors.size(); i++) {
      if (factors[i].second == 0) continue;
      int p = factors[i].first;
      int cnt = 0;
      while (x % p == 0) {
        cnt++;
        x /= p;
      }
      if (cnt >= factors[i].second) factors[i].second = 0;
    }
  }
  REP(i, factors.size()) if (factors[i].second) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;


  return 0;
}



