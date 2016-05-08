/*************************************************************************
  > File Name: A.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 30 Apr 2016 11:59:17 PM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

string str[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[10] = {0, 2, 4, 6, 8, 7, 3, 1, 5, 9};
string key = "ZWUXGSHOFI";
int cnt[26];
int a[10][26];

int main() {
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

  ios::sync_with_stdio(0);
  REP(i, 10) {
    REP(j, str[i].size()) {
      a[i][str[i][j] - 'A']++;
    }
  }
  int t, ca = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    //cout << s << endl;
    REP(i, 26) cnt[i] = 0;
    int n = s.size();
    REP(i, n) cnt[s[i] - 'A']++;
    string ans;
    REP(i, 10) {
      int index = order[i];
      int num = key[i] - 'A';
      ans += string(cnt[num], index + '0');
      //cout << i << ' ' << index << ' ' << cnt[num] << ' ' << ans << endl;
      int now = cnt[num];
      REP(j, 26) {
        cnt[j] -= now * a[index][j];
      }
    }
    sort(ans.begin(), ans.end());
    cout << "Case #" << ca++ << ": " << ans << endl;
  }



  return 0;
}


