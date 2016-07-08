#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (auto i = (a); i <= (b); i++)
using namespace std;

int update(int a, int b, int c) {
  int x = max(a, max(b, c));
  if (x > (a + b + c + 1) / 2) return 2 * (a + b + c - x) + 1;
  else return a + b + c;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i < 200; i++) {
      REP(j, 200) {
        REP(k, 200) {
          if (i + j + 2 * k <= a && i + 2 * j + k <= b && i <= c) {
            ans = max(ans, update(i, j, k));
          }
        }
      }
    }
    //assert(ans == (a + b + c) / 3);
    cout << ans << endl;
  }

  return 0;
}


