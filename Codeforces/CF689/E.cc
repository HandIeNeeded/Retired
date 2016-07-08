/*************************************************************************
	> File Name: E.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 08 Jul 2016 04:01:10 PM CST
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

const int N = 4e5 + 5;
const int MO = 1e9 + 7;
int a[N], b[N], k, n;
int cnt[N << 2], sum[N << 2];
int fac[N], inv[N];
vector<int> numbers;

void Init() {
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  REPP(i, 2, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
  REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
  REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

void add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return 1LL * fac[a] * inv[b] % MO * inv[a - b] % MO;
}

int ql, qr;

void update(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    cnt[x]++;
  }
  else {
    if (ql <= MID) update(LC);
    if (qr > MID) update(RC);
  }
}

void build(int x, int l, int r, int now = 0) {
  if (l == r) {
    now += cnt[x];
    //cout << x << ' ' << l << ' ' << r << ' ' << now << endl;
    sum[x] = 1LL * C(now, k) * (numbers[r] - numbers[l - 1]) % MO;
  }
  else {
    build(LC, now + cnt[x]), build(RC, now + cnt[x]);
    sum[x] = sum[L];
    add(sum[x], sum[R]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  Init();
  cin >> n >> k;
  REPP(i, 1, n) {
    int a, b;
    cin >> a >> b;
    numbers.push_back(a);
    numbers.push_back(b + 1);
    ::a[i] = a, ::b[i] = b;
  }
  sort(numbers.begin(), numbers.end());
  numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());
  int tot = numbers.size();
  //numbers.push_back(numbers.back() + 1);
  REPP(i, 1, n) {
    int x = lower_bound(numbers.begin(), numbers.end(), a[i]) - numbers.begin() + 1;
    int y = lower_bound(numbers.begin(), numbers.end(), b[i] + 1) - numbers.begin();
    ql = x, qr = y;
    //cout << ql << ' ' << qr << endl;
    update(1, 1, tot);
  }
  build(1, 1, tot);
  cout << sum[1] << endl;

  return 0;
}

