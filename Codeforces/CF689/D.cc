/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 08 Jul 2016 03:38:34 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 2e5 + 5;
const int L = 20;
int a[N], b[N], n;
int f[N][L], g[N][L];

void Init() {
  REPP(i, 1, n) f[i][0] = a[i], g[i][0] = b[i];
  REPP(i, 1, L - 1) {
    REPP(j, 1, n) if (j + (1 << i) - 1 <= n) {
      f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
      g[j][i] = min(g[j][i - 1], g[j + (1 << (i - 1))][i - 1]);
    }
  }
}

int GetA(int l, int r) {
  int now = 0;
  while ((1 << (now + 1)) < (r - l + 1)) now++;
  return max(f[l][now], f[r - (1 << now) + 1][now]);
}

int GetB(int l, int r) {
  int now = 0;
  while (1 << (now + 1) < (r - l + 1)) now++;
  return min(g[l][now], g[r - (1 << now) + 1][now]);
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  REPP(i, 1, n) cin >> a[i];
  REPP(i, 1, n) cin >> b[i];
  Init();
  LL ans = 0;
  REPP(i, 1, n) {
    int lo = i - 1, hi = n;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      int x = GetA(i, mid);
      int y = GetB(i, mid);
      if (x < y) lo = mid;
      else hi = mid;
    }
    int x = GetA(i, hi), y = GetB(i, hi);
    //cout << x << ' ' << y << endl;
    if (x != y) continue;
    else {
      int l = hi, r = n + 1;
      int pl, pr;
      while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (GetA(i, mid) == x) l = mid;
        else r = mid;
      }
      pl = l;
      l = hi, r = n + 1;
      while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (GetB(i, mid) == x) l = mid;
        else r = mid;
      }
      pr = l;
      ans += min(pl, pr) - hi + 1;
    }
  }
  cout << ans << endl;

  return 0;
}


