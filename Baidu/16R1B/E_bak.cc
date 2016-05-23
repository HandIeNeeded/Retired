/*************************************************************************
	> File Name: E.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 03:05:54 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;
const int N = 1e5 + 5;

int cnt[N << 2], a[N], b[N];

struct Segment {
  LL left, right, sum;
  int prefix, suffix, l, r;

  Segment operator + (const Segment& rhs) const {
    Segment answer = (Segment) {0, 0, 0};
    answer.l = l, answer.r = rhs.r;
    answer.prefix = (prefix == r) ? rhs.prefix : prefix;
    answer.suffix = (rhs.suffix == rhs.l) ? suffix : rhs.suffix;
    answer.left = (prefix == r) ? left + rhs.left : left;
    answer.right = (rhs.suffix == rhs.l) ? rhs.right + right : rhs.right;
    answer.sum = max(sum, rhs.sum);
    answer.sum = max(answer.sum, right + rhs.left);
    return answer;
  }
}p[N << 2];

int ql, qr, qx;
int n, m, k;

void build(int x, int l, int r) {
  if (l == r) {
    p[x] = (Segment) {0, 0, 0};
    cnt[x] = 0;
  }
  else {
    build(LC), build(RC);
    p[x] = (Segment) {0, 0, 0};
    cnt[x] = 0;
  }
}

void Build(int x, int l, int r) {
  if (l == r) {
    if (b[l] >= k) {
      p[x] = (Segment) {a[l], a[l], a[l], l, l, l, l};
    }
    else p[x] = (Segment) {0, 0, 0, l, l, l, l};
  }
  else {
    Build(LC), Build(RC);
    p[x] = p[L] + p[R];
  }
  //cout << "(" << x << ' ' << l << ' ' << r << "): " << p[x].sum << endl;
}

void update(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    cnt[x]++;
  }
  else {
    if (ql <= MID) update(LC);
    if (qr > MID) update(RC);
  }
}

int query(int x, int l, int r) {
  if (l == r) return cnt[x];
  else {
    if (qx <= MID) return cnt[x] + query(LC);
    else return cnt[x] + query(RC);
  }
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  while (scanf("%d%d%d", &n, &k, &m) > 0) {
    REPP(i, 1, n) scanf("%d", a + i);
    build(1, 1, n);
    REP(i, m) {
      scanf("%d%d", &ql, &qr);
      update(1, 1, n);
    }
    REPP(i, 1, n) {
      qx = i;
      b[i] = query(1, 1, n);
    }
    //REPP(i, 1, n) cout << i << ' ' << b[i] << endl;
    Build(1, 1, n);
    cout << p[1].sum << endl;
  }
  return 0;
}

