/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 02:45:54 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 5e5 + 5;
int a[N], n;
int p[N], vis[N], tot;

void prime() {
  for (int i = 2; i < N; i++) {
    if (!vis[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}

int get(int x) {
  int ans = 0;
  vector<int> fac;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      fac.push_back(i);
    }
  }
  int tot = fac.size();
  for (int i = tot - 1; i >= 0; i--) {
    if (x / fac[i] > fac[i]) {
      fac.push_back(x / fac[i]);
    }
  }
  REP(i, n) {
    int y = fac[upper_bound(fac.begin(), fac.end(), a[i]) - fac.begin() - 1];
    //cout << x << ' ' << y << ' ' << a[i] << endl;
    int k = a[i] / y, b = a[i] % y;
    if (b == 0 || y % b == 0) ans += k;
    else return INT_MAX;
    if (b) ans++;
  }
  return ans;
}

int main() {
  prime();
  cin >> n;
  REP(i, n) cin >> a[i];
  int ans = INT_MAX;
  REPP(i, 1, 1000000) {
    ans = min(ans, get(i));
  }
  cout << ans << endl;

  return 0;
}


