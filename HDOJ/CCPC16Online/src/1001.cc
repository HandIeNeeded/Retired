/*************************************************************************
  >         File: 1001.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 14 Aug 2016 02:36:57 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

char s[12345678];

int go(char *s, int x) {
  int n = strlen(s);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = 10 * ans + s[i] - '0';
    ans %= x;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  int ca = 1;
  while (scanf("%s", s) > 0) {
    cout << "Case #" << ca++ << ": ";
    if (go(s, 73) == 0 && go(s, 137) == 0) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
