#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  srand(time(0) % clock());
  int n = rand() % 10000 + 4;
  cout << n << endl;
  REP(i, n) {
    cout << rand() % int(1e9) - int(5e8) << ' ';
  }
  cout << endl;
  return 0;
}



