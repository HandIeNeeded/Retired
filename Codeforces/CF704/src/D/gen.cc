#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  srand(time(0) * clock());
  int n = rand() % 8 + 1, m = rand() % 10 + 2;
  int r = rand() % 100 + 1, b = rand() % 100 + 1;
  cout << n << ' ' << m << endl;
  cout << r << ' ' << b << endl;
  vector<int> A, B;
  for (int i = 0; i < n; i++) {
    int x = rand() % 20 + 1, y = rand() % 20 + 1;
    cout << x << ' ' << y << endl;
    A.push_back(x), B.push_back(y);
  }
  for (int i = 0; i < m; i++) {
    int t = rand() % 2 + 1;
    int y = max(rand() % (n + 1) - 3, rand() % 2);
    int x;
    if (t == 1) {
      x = A[rand() % A.size()];
    }
    else {
      x = B[rand() % B.size()];
    }
    if (rand() % 7 == 0) {
      x = rand() % 20 + 1;
    }
    cout << t << ' ' << x << ' ' << y << endl;
  }
  return 0;
}


