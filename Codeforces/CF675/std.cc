/*************************************************************************
	> File Name: E.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Tue 17 May 2016 01:45:24 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

const int N = 1e5 + 5;
LL sum[N << 2], flag[N << 2], cover[N << 2];
int v[N], ql, qr, n;

void modify(int x, int l, int r) {
  REPP(i, ql, qr) v[i] = 1;
}

void update(int x, int l, int r) {
  REPP(i, ql, qr) v[i]++;
}

LL query() {
  LL ans = 0;
  REPP(i, 1, n) ans += v[i];
  return ans;
}

int a[N];

int main() {
  scanf("%d", &n);
  REPP(i, 1, n - 1) {
    scanf("%d", a + i);
  }
  LL ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    ql = i + 1, qr = a[i];
    modify(1, 1, n);
    ql = a[i] + 1, qr = n;
    if (ql <= qr) {
      update(1, 1, n);
    }
    ans += query();
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}

