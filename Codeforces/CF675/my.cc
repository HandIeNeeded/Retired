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

void build(int x, int l, int r) {
  if (l == r) {
    sum[x] = flag[x] = 0;
  }
  else {
    build(LC), build(RC);
    sum[x] = flag[x] = cover[x] = 0;
  }
}

int ql, qr;

void push(int x, int l, int r) {
  if (cover[x]) {
    cover[L] = cover[R] = 1;
    flag[L] = flag[R] = flag[x];
    sum[L] = (1 + flag[x]) * (MID - l + 1);
    sum[R] = (1 + flag[x]) * (r - MID);
    cover[x] = flag[x] = 0;
  }
  else {
    flag[L] += flag[x], flag[R] += flag[x];
    sum[L] += flag[x] * (MID - l + 1);
    sum[R] += flag[x] * (r - MID);
    flag[x] = 0;
  }
}

void update(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    flag[x] += 1;
    sum[x] += (r - l + 1);
  }
  else {
    push(x, l, r);
    if (ql <= MID) update(LC);
    if (qr > MID) update(RC);
    sum[x] = sum[L] + sum[R];
  }
}

void modify(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    cover[x] = 1, flag[x] = 0;
    sum[x] = r - l + 1;
  }
  else {
    push(x, l ,r);
    if (ql <= MID) modify(LC);
    if (qr > MID) modify(RC);
    sum[x] = sum[L] + sum[R];
  }
}

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  REPP(i, 1, n - 1) {
    scanf("%d", a + i);
  }
  build(1, 1, n);
  LL ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    ql = i + 1, qr = a[i];
    modify(1, 1, n);
    ql = a[i] + 1, qr = n;
    if (ql <= qr) {
      update(1, 1, n);
    }
    ans += sum[1];
    cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}

