/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri 13 Jan 2017 12:43:13 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 333;
int cnt[2][N];

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  std::string str = "Bulbasaur";
  int n = s.size();
  int ans = n + 1;
  for (int i = 0; i < str.size(); ++i) cnt[0][str[i]]++;
  for (int i = 0; i < n; ++i) {
    cnt[1][s[i]]++;
  }
  for (int i = 0; i < N; ++i) if (cnt[0][i]) {
    ans = std::min(ans, cnt[1][i] / cnt[0][i]);
  }
  std::cout << ans << std::endl;


  return 0;
}
