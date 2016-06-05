/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 05 Jun 2016 11:30:51 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 30;
int cnt[N];

int get(const string &str) {
  int ans = 0;
  if (str.size() < 2) return 0;
  for (int i = 1; i < (int) str.size(); i++) {
    int result = 0;
    for (int j = 1; j <= i; j++) {
      if (str.substr(0, i - j + 1) == str.substr(j, i - j + 1)) {
        result = i - j + 1;
        break;
      }
    }
    ans += result;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    REP(i, 26) cin >> cnt[i];
    int has = 0;
    REP(i, 26) if (cnt[i]) has |= 1 << i;
    if (has == 0) {
      cout << 0 << endl;
    }
    else if ((has & (has - 1)) == 0) {
      REP(i, 26) if (cnt[i]) {
        cout << cnt[i] * (cnt[i] - 1) / 2 << endl;
        break;
      }
    }
    else {
      string str;
      int pos = -1, best = 100;
      REP(i, 26) {
        if (cnt[i] && cnt[i] < best) {
          pos = i;
          best = cnt[i];
        }
      }
      str += pos + 'a';
      cnt[pos]--;
      REP(i, 26) if (i != pos && cnt[i]) {
        cnt[i]--;
        str += i + 'a';
        break;
      }
      if (str[0] > str[1]) {
        REP(i, 26) {
          while (cnt[i]) {
            str += i + 'a';
            cnt[i]--;
          }
        }
      }
      else {
        for (int i = 25; i >= 0; i--) {
          while (cnt[i]) {
            str += i + 'a';
            cnt[i]--;
          }
        }
      }
      cout << get(str) << endl;
    }
  }
  return 0;
}


