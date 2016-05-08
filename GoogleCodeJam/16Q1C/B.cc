/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 08 May 2016 05:37:22 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 55;
char mp[N][N];
int tmp[N];

int main() {
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

  int t, ca = 1;
  cin >> t;
  while (t--) {
    int n;
    LL m;
    cin >> n >> m;
    int length = 0;
    while ((1LL << (length + 1)) <= m) length++;
    cout << "Case #" << ca++ << ": ";
    REPP(i, 1, n) REPP(j, 1, n) mp[i][j] = '0';
    REPP(i, 1, n) mp[i][n + 1] = 0;
    //cerr << n << ' ' << m << endl;
    if ((m & (m - 1)) == 0) {
      int need = length + 2;
      if (need > n) {
        cout << "IMPOSSIBLE" << endl;
        continue;
      }
      cout << "POSSIBLE" << endl;
      REPP(i, 1, need) tmp[i] = i;
      tmp[need] = n;
      REPP(i, 1, need) {
        REPP(j, i + 1, need) {
          mp[tmp[i]][tmp[j]] = '1';
        }
      }
      //cerr << "Case : " << ca - 1 << ' ' << n << ' ' << m <<endl;
      REPP(i, 1, n) cout << mp[i] + 1 << endl;
    }
    else {
      //cerr << "Case : " << ca - 1 << ' ' << n << ' ' << m << endl;
      int need = length + 3;
      if (need > n) {
        cout << "IMPOSSIBLE" << endl;
      }
      else {
        cout << "POSSIBLE" << endl;
        REPP(i, 1, need - 1) tmp[i] = i;
        tmp[need] = n;
        REPP(i, 1, need - 1) REPP(j, i + 1, need - 1) {
          mp[tmp[i]][tmp[j]] = '1';
        }
        REPP(i, 1, need - 1) if (m & (1LL << (i - 1))) {
            mp[tmp[i + 1]][tmp[need]] = '1';
        }
        REPP(i, 1, n) {
          cout << mp[i] + 1 << endl;
        }
      }
    }
  }


  return 0;
}



