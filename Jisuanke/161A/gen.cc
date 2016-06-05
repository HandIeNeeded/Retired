#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1000;

int f[N];

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
  int n;
  srand(time(0) * clock());
  n = rand() % 5 + 2;
  cout << n << endl;
  REP(i, n) {
    cout << rand() % 20 + 1 << ' ';
  }
  cout << endl;
  REPP(i, 1, n) f[i] = i;
  int cnt = n;
  while (cnt > 1) {
    int x = rand() % n + 1, y = rand() % n + 1;
    int tx = find(x), ty = find(y);
    if (tx != ty) {
      cout << x << ' ' << y << endl;
      f[tx] = ty;
      cnt--;
    }
  }

  return 0;
}


