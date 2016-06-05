/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 09:56:36 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 4e6 + 6;
const int MO = 1e9 + 7;
int  fac[N], inv[N];

void Init() {
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
  REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
  REPP(i, 1, N - 1) inv[i] = 1LL * inv[i] * inv[i - 1] % MO;
}

void add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int C(int x, int y) {
  return 1LL * fac[x] * inv[x - y] % MO * inv[y] % MO;
}

int get(int a, int b) {
  //x1 + x2 + ... + xb = a;
  //xi >= 0
  return C(a + b - 1, b - 1);
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

  int w, m, p;
  Init();
  //REP(i, 10) {
  //  cout << fac[i] << ' ' << inv[i] << endl;
  //}
  cin >> m >> w >> p;
  if (w == 0 || m == 0) {
    cout << fac[w + m] << endl;
    return 0;
  }
  w -= p, m -= p;
  int answer = 0;
  REPP(i, 1, p) {
    int a = (p + 2) / 2;
    int b = (p + 1) - a;
    int women = w + (p - i), man = m + (p - i);
    int  result = 0;
    //first pair is (man women)
    int ans1 = get(women, a);
    int ans2 = get(man, b);
    add(result, 1LL * ans1 * ans2 % MO);
    //reverse
    ans1 = get(man, a);
    ans2 = get(women, b);
    add(result, 1LL * ans1 * ans2 % MO);

    result = 1LL * result * C(p, i) % MO;
    result = 1LL * result * fac[women] % MO * fac[man] % MO;
    add(answer, result);
  }
  cout << answer << endl;

  return 0;
}
