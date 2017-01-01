/*************************************************************************
  >         File: F.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Dec 31 01:10:34 2016
*************************************************************************/
#include <vector>
#include <cstdio>
#include <cassert>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

const int N = 222;

std::vector<int> ans;
int h, cnt;
std::vector<int> history[N];
bool find;


void print(int x) {
  std::cout << "! " << x << std::endl;
}

void ask(int x) {
  ++cnt;
  if (cnt > 16) {
    print(x);
    find = 1;
    return;
  }
  std::cout << "? " << x << std::endl;
  int n;
  std::cin >> n;
  ans.clear();
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ans.push_back(x);
  }
  history[x] = ans;
}

void findLeaf(int x, int start, std::vector<int> &res) {
  res.emplace_back(x);
  if (!history[x].size()) {
    ask(x);
  }
  if (history[x].size() == 1) {
    if (x != start) return;
  } else if (int(history[x].size()) == 2) {
    print(x);
    find = 1;
    return ;
  }
  for(auto &y: history[x]) if (!history[y].size()) {
    findLeaf(y, start, res);
    return;
  }
}

int getLca(std::vector<int> &chain) {
  assert(chain.size() & 1);
  chain.resize((chain.size() + 1) >> 1);
  return chain.back();
}

void dfs(int x, int dep, int limit) {
  if (dep == limit) return;
  if (!history[x].size()) {
    ask(x);
    if (history[x].size() == 2) {
      find = 1;
      print(x);
      return;
    }
  }
  for (auto &y: history[x]) if (!history[y].size()) {
    dfs(y, dep + 1, limit);
    if (find) return;
  }
}

void go() {
  if (h < 5) {
    for (int i = 0; i < (1 << h); ++i) {
      if (i) {
        ask(i);
        if ((int) ans.size() == 2) {
          print(i);
          return;
        }
      }
    }
  }
  int seed = 1;
  std::vector<int> chain;
  findLeaf(seed, seed, chain);
  if (find) return;
  std::reverse(chain.begin(), chain.end());
  int chainCnt = 1;
  while (chainCnt < 2 || (int) chain.size() < 4) {
    chainCnt++;
    std::vector<int> tmp;
    findLeaf(seed, seed, tmp);
    if (find) return;
    chain.insert(chain.end(), tmp.begin() + 1, tmp.end());
    seed = getLca(chain);
  }
  int d = h - chain.size();
  assert(d);
  for (auto &y: history[seed]) if (!history[y].size()) {
    dfs(y, 0, d);
    if (find) return;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> h;
    cnt = find = 0;
    for (int i = 0; i < (1 << h); ++i) history[i].clear();
    go();
  }
  return 0;
}
