/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 24 Sep 2016 08:36:27 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using pii = std::pair<int, int>;
map<std::pair<int, int>, int> mp;
set<std::pair<int, int>> row[N], column[N];

int dx[] = {0, 0, 1, 1}, dy[] = {0, 1, 0, 1};

std::pair<pii, int> Get(std::vector<pii>& points) {
  return {{points[0].first + points[2].first - points[1].first, points[0].second + points[2].second - points[1].second}, 
         mp[points[0]] + mp[points[2]] - mp[points[1]]};
}

bool exist(std::pair<int, int> a) {
  return mp.count(a);
}

bool check(vector<pii> &points) {
  return mp[points[0]] + mp[points[3]] == mp[points[1]] + mp[points[2]];
}

inline void NO() {
  std::cout << "No" << std::endl;
  exit(0);
}

inline void YES() {
  std::cout << "Yes" << std::endl;
  exit(0);
}

void update(std::pair<pii, int> &now) {
  mp[now.first] = now.second;
  row[now.first.first].insert(now.first);
  column[now.first.second].insert(now.first);
}

int main() {
  std::ios::sync_with_stdio(0);
  int r, c;
  std::cin >> r >> c;
  int n;
  std::cin >> n;
  std::priority_queue<pii, vector<pii>, greater<pii>> q;
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    mp[{x, y}] = z;
    q.emplace(x, y);
    row[x].insert({x, y});
    column[y].insert({x, y});
  }
  while (q.size()) {
    vector<pii> candidates;
    pii corner = q.top(); q.pop();
    int x, y;
    std::tie(x, y) = corner;
    auto right = row[x].upper_bound(corner);
    if (right == row[x].end()) continue;
    auto down = column[y].upper_bound(corner);
    if (down == column[y].end()) continue;
    candidates.push_back(corner);
    candidates.push_back(*right);
    candidates.push_back(*down);
    std::sort(candidates.begin(), candidates.end());
    std::pair<pii, int> newPoint = Get(candidates);
    if (newPoint.second < 0) {
      NO();
    }
    if (!exist(newPoint.first)) {
      update(newPoint);
      q.push(newPoint.first);
    } else if (mp[newPoint.first] != newPoint.second) {
      NO();
    }
  }
  for (auto &kv: mp) {
    pii point;
    int value;
    tie(point, value) = kv;
    std::cerr << "Point: (" << point.first << ", " << point.second <<  ") value: " << value << std::endl;
  }
  YES();
  return 0;
}
