/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue 21 Feb 2017 01:29:25 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 666;
int sg[N] = {0, 1};

void getSG() {
  int now = 0;
  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j <= i; ++j) {
      sg[++now] = i;
    }
  }
}

int ans;
std::map<std::pair<int, std::set<int>>, int> history;

int dfs(int x, std::set<int> &numbers) {
  if (x == 0) return 0;
  else if (history.count(std::make_pair(x, numbers))) return history[{x, numbers}];
  else {
    bool vis[200] = {0};
    int isFinal = 1;
    for (int i = 1; i <= x; ++i) {
      if (!numbers.count(i)) {
        isFinal = 0;
        numbers.insert(i);
        vis[dfs(x - i, numbers)] = 1;
        numbers.erase(i);
      }
    }
    if (isFinal) return history[{x, numbers}] = 0;
    int &ans = history[std::make_pair(x, numbers)];
    while (vis[ans]) ++ans;
    return ans;
  }
}


int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::set<int> tmp;
  //for (int i = 0; i < 40; ++i) {
  //  ans = 0;
  //  sg[i + 1] = dfs(i + 1, tmp);
  //  std::cout << i + 1 << ' ' << sg[i + 1] << std::endl;
  //}
  getSG();
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ans ^= sg[x];
  }
  !ans ? puts("YES") : puts("NO");

  return 0;
}
