#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  srand(time(0) % clock());
  int n = rand() % 3 + 10;
  cout << n << endl;
  REP(i, n) {
    int type = rand() % 3 + 1;
    int pos = rand() % 10 + 1;
    int num = rand() % 10 + 1;
    cout << type << ' ' << pos << ' ' << num << endl;
  }
  return 0;
}


