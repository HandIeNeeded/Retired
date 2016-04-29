#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 100000;
multiset<int> s[N];

int main() {
    int n;
    cin >> n;
    REP(i, n) {
      int a, b, c;
      cin >> a >> b >> c;
      if (a == 1) {
        REPP(i, b, 20) s[i].insert(c);
      }
      else if (a == 2) {
        REPP(i, b, 20) {
          auto pos = s[i].find(c);
          if (pos != s[i].end()) s[i].erase(pos);
        }
      }
      else {
        cout << s[b].count(c) << endl;
      }
    }
    return 0;
}


