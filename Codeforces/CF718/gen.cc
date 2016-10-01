#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  srand(time(0) * clock());
  int n = 200000, m = 2000;
  std::cout << n << ' ' << m << std::endl;
  for (int i = 0; i < n; ++i) std::cout << rand() % 1000 + 1 << ' ';
  std::cout << endl;
  for (int i = 0; i < m; ++i) std::cout << rand() % int(1e9) + 1 << ' ';
  std::cout << endl;


  return 0;
}


