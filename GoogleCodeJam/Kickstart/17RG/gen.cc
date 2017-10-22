#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  srand(time(0) * clock());
  int t = 1;
  std::cout << t << std::endl;
  for (int i = 0; i  < t; ++i) {
    int A = rand() % 100 + 1;
    int P = rand() % 100 + 1;
    int N = rand() % 6 + 1;
    std::cout << A << ' ' << N << ' ' << P << std::endl;
  }

  return 0;
}


