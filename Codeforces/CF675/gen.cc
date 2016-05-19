#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int t, ca = 1;
  srand(time(0) % clock());
  int n = rand() % 500 + 3;
  cout << n << endl;
  REPP(i, 1, n - 1) {
    int length = n - i;
    int x = rand() % length;
    cout << x + i + 1 << ' ';
  }
  cout << endl;
  return 0;
}



