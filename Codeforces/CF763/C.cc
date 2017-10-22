/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri 03 Feb 2017 12:08:56 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
int a[N], b[N];

void NO() {
  std::cout << -1 << std::endl;
  exit(0);
}

bool ban[N];
std::vector<int> tmp;
std::map<int, int> cntD;

int getOne(std::vector<int> &candidates) {
  if (candidates.size() == 1) return candidates[0];
  int x = rand() % candidates.size();
  cntD.clear(), tmp.clear();
  for (int i = 0; i < candidates.size(); ++i) if (candidates[i] != x) {
    cntD[std::abs(candidates[i] - x)]++;
  }

}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> m >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::map<int, int> cnt;
  for (int i = 0; i < n; ++i) cnt[a[i]]++;
  int mi = n + 1, mx = -1;
  for (auto &p: cnt) {
    if (mi > p.second) mi = p.second;
    if (mx < p.second) mx = p.second;
  }
  if (mx - mi > 1) NO();
  int a = 0;
  for (auto &p: cnt) {
    if (p.second == mx && p.second != mi) a++;
  }
  int T = n - a;
  if (T % m) NO();
  if (a == 0) {
    std::cout << "0 1" << std::endl;
    return 0;
  } else if (a == 1) {
    for (auto &p: cnt) {
      if (p.second == mx) {
        std::cout << p.first << ' ' << 1 << std::endl;
        return 0;
      }
    }
  } else if (a == 2) {
    std::vector<int> candidates;
    for (auto &p: cnt) {
      if (p.second == mx) {
        candidates.push_back(p.first);
      }
    }
    std::cout << candidates[0] << ' ' << (candidates[0] - candidates[1] + m) % m << std::endl;
    return 0;
  } else {
    //a >= 3
    std::vector<int> candidates;
    for (auto &p: cnt) {
      if (p.second == mx) {
        candidates.push_back(p.first);
      }
    }
    int end = getOne(candidates);
    int begin = getAnother(end);
    getD(begin, end, candidates);
  }
  return 0;
}
