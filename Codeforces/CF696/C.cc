/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 15 Jul 2016 01:14:27 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 2;
const int MO = 1e9 + 7;
const int K = 5e8 + 4;

struct Matrix {
  int a[N][N];

  Matrix (bool ident = 0) {
    REP(i, N) REP(j, N) a[i][j] = 0;
    if (ident) {
      REP(i, N) a[i][i] = 1;
    }
  }

  int* operator [] (int i){
    return a[i];
  }

  const int* operator [] (int i) const {
    return a[i];
  }
};

void add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
  Matrix c;
  REP(i, N) REP(j, N) REP(k, N) {
    add(c[i][j], 1LL * a[i][k] * b[k][j] % MO);
  }
  return c;
}

Matrix powd(Matrix a, LL b) {
  Matrix ans(1);
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

int powd(int a, LL b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % MO;
    b >>= 1;
    a = 1LL * a * a % MO;
  }
  return ans;
}

int main() {
  Matrix magic;
  magic[0][0] = magic[1][0] = 1, magic[0][1] = 2;

  //Matrix ans(1);
  //REP(i, 5) {
  //  ans = ans * magic;
  //  REP(i, N) {
  //    REP(j, N) {
  //      cout << ans[i][j].first << '/' << ans[i][j].second << '\t';
  //    }
  //    cout << endl;
  //  }
  //  cout << endl;
  //}

  int n;
  cin >> n;
  Matrix now = magic;
  int down = 2;
  REP(i, n) {
    LL x;
    scanf("%I64d", &x);
    now = powd(now, x);
    //REP(i, N) {
    //  REP(j, N) {
    //    cout << now[i][j].first << '/' << now[i][j].second << '\t';
    //  }
    //  cout << endl;
    //}
    //cout << endl;
    down = powd(down, x);
  }
  cout << 1LL * now[1][1] * K % MO << "/" << 1LL * down * K % MO << endl;

  return 0;
}


