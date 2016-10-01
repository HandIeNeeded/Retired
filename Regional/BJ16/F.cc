/*************************************************************************
  >         File: F.cc
  >       Author: lyyLLyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 24 Sep 2016 04:24:29 PM CST
 *************************************************************************/
//
//  Created by 赵宏祝 .
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <iterator>

#define FOR0(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define FOR1(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define FOR(i, l, r) for(int (i) = (l); (i) <= (r); (i)++)
#define lowbit(x) (x)&(-x)
#define MEMSET(x, y) memset((x), (y), sizeof(x))

using namespace std;
//============================
typedef long long LL;
int T;
int N;
const int maxn = 800000;
int a[800000], b[800000], c1[800000], c2[800000];
//============================
const int g1 = 3;
const int g2 = 3;			//G为原根，模数不同原根不同。
const int Mod1 = 998244353;
const int Mod2 = 1004535809;
int mo, g;

void Add(LL &x, LL y, LL MO) {
  x += y;
  if (x >= MO) x -= MO;
}

LL quickplus(LL x, LL n, LL MOD) {
  LL ans = 0;
  x %= MOD;
  for (; n > 0; n >>= 1) {
    if (n & 1) Add(ans, x, MOD);
    Add(x, x, MOD);
  }
  return ans;
}

LL chinaa[3], mod[3]; //x == a[i] (mod mod[i]), i = 0, 1, ... , n − 1

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
  if (!b) d = a, x = 1, y = 0;
  else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

LL china(LL n, LL *a, LL *mod) {
  LL re = 0, M = 1;
  FOR0(i, n) M *= mod[i];
  FOR0(i, n) {
    LL d, x, y;
    exgcd(M / mod[i], mod[i], d, x, y);
    if (x < 0) x += M;
    LL t1 = quickplus(M / mod[i], x, M);
    t1 = quickplus(t1, a[i], M);
    Add(re, t1, M);
  }
  Add(re, M, M);
  return re;
}

struct NTT{
  int n, y[maxn];

  void init(int _n){
    n = 1;
    while (n < _n){
      n <<= 1;
    }
    for (int i = 0; i < n; ++ i){
      y[i] = 0;
    }
  }

  int mul(int a, int k){
    int ret = 1;
    while (k){
      if (k & 1){
        ret = 1LL * ret * a % mo;
      }
      a = 1LL * a * a % mo;
      k >>= 1;
    }
    return ret;
  }

  void change(){
    int i, j, k;
    for (i = 1, j = n / 2; i < n - 1; ++ i){
      if (i < j) swap(y[i], y[j]);
      k = n / 2;
      while (j >= k){
        j -= k;
        k /= 2;
      }
      if (j < k){
        j += k;
      }
    }
  }

  void fft(int on){ // 1 for DFT -1 for IDFT
    change();
    for (int h = 2; h <= n; h <<= 1){
      int wn = mul(g, (mo - 1) / h);
      if (on == -1) wn = mul(wn, mo - 2);
      for (int j = 0; j < n; j += h){
        int w = 1;
        for (int k = j; k < j + h / 2; ++ k){
          int u = y[k];
          int t = 1LL * w * y[k+h/2] % mo;
          y[k] = (u + t) % mo;
          y[k+h/2] = ((u - t) % mo + mo) % mo;
          w = 1LL * w * wn % mo;
        }
      }
    }
    if (on == -1){
      int invn = mul(n, mo - 2);
      for (int i = 0; i < n; ++ i){
        y[i] = 1LL * y[i] * invn % mo;
      }
    }
  }

}A, B, C;

void solve(int na, int a[], int nb, int b[], int c[], int n){
  A.init(n);
  for (int i = 0; i < na; ++ i){
    A.y[i] = a[i];
  }
  B.init(n);
  for (int i = 0; i < nb; ++ i){
    B.y[i] = b[i];
  }

  A.fft(1);
  B.fft(1);
  C.init(n);
  for (int i = 0; i < C.n; ++ i){ //另外注意该处需要用C.n这个扩展长度
    C.y[i] = 1LL * A.y[i] * B.y[i] % mo;
  }
  C.fft(-1);

  for (int i = 0; i < C.n; ++ i){
    c[i] = C.y[i];
  }
}

int main(){
  LL ta2, tb2, tans;
  scanf("%d", &T);
  while (T--) {
    ta2 = 0, tb2 = 0;
    tans = 9e18;
    //memset(a, 0, sizeof(a));
    //memset(b, 0, sizeof(b));
    //memset(c2, 0, sizeof(c2));
    //memset(c1, 0, sizeof(c1));
    scanf("%d", &N);
    std::fill(a, a + 8 * N, 0);
    std::fill(b, b + 8 * N, 0);
    std::fill(c2, c2 + 8 * N, 0);
    std::fill(c1, c1 + 8 * N, 0);
    FOR0(i, N) {
      scanf("%d", &a[i]);
      ta2 += 1LL * a[i] * a[i];
    }
    FOR0(i, N) {
      scanf("%d", &b[N - i - 1]);
      b[2 * N - i - 1] = b[N - i - 1];
      tb2 += 1LL * b[N - i - 1] * b[N - i - 1];
    }
    int t = 1;
    int len1 = N, len2 = 2 * N;
    while(t < len1*2 || t < len2*2) t <<= 1;
    mod[0] = mo = Mod1, g = g1;
    solve(N, a, 2 * N, b, c1, t);
    mod[1] = mo = Mod2, g = g2;
    solve(N, a, 2 * N, b, c2, t);
    for(int i = N - 1 ;i < 2 * N - 1;i++) {
      chinaa[0] = c1[i];
      chinaa[1] = c2[i];
      tans = min(tans, -2 * china(2, chinaa, mod));
    }
    cout << tans + ta2 + tb2  << endl;
  }
  return 0;
}
