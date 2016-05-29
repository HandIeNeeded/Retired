/*************************************************************************
	> File Name: 1003.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 29 May 2016 02:17:28 PM CST
*************************************************************************/
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <utility>
#include <functional>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>

typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

struct Segment {
  int x, y, z, d;
  Segment(int _x, int _y, int _z, int _d) :x(_x), y(_y), z(_z), d(_d) {}
};

vector<Segment> Left, Right;

bool cmp(const Segment& a, const Segment& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const int N = 1e5 + 5;
int cnt[N], tot;

int LB(int x) {
  return x & (-x);
}

void add(int x, int d) {
  while (x <= tot) {
    cnt[x] += d;
    x += LB(x);
  }
}

int query(int x) {
  int answer = 0;
  while (x) {
    answer += cnt[x];
    x -= LB(x);
  }
  return answer;
}

void getAnswer(vector<Segment>& v, vector<pair<int, int> > &result) {
  vector<int> numbers;
  vector<pair<int, int> > positions;
  positions.reserve(v.size() * 2);
  numbers.reserve(v.size() * 4);
  REP(i, v.size()) {
    positions.push_back(make_pair(v[i].x, v[i].x + v[i].z * 2));
    positions.push_back(make_pair(v[i].y - v[i].z * 2, v[i].y));
    numbers.push_back(v[i].x);
    numbers.push_back(v[i].x + v[i].z * 2);
    numbers.push_back(v[i].y - v[i].z * 2);
    numbers.push_back(v[i].y);
  }
  sort(positions.begin(), positions.end());
  positions.resize(unique(positions.begin(), positions.end()) - positions.begin());
  sort(v.begin(), v.end(), cmp);
  sort(numbers.begin(), numbers.end());
  numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());
  tot = numbers.size();
  int now = 0;
  REP(i, tot + 1) cnt[i] = 0;
  for (int i = 0; i < v.size(); i++) {
    v[i].x = lower_bound(numbers.begin(), numbers.end(), v[i].x) - numbers.begin() + 1;
    v[i].y = lower_bound(numbers.begin(), numbers.end(), v[i].y) - numbers.begin() + 1;
  }
  for (int i = 0; i < v.size(); i++) {
    add(v[i].y, 1);
  }
  result.clear();
  for (int i = 0; i < positions.size(); i++) {
    while (now < v.size() && numbers[v[now].x - 1] < positions[i].first) {
      add(v[now].y, -1);
      now++;
    }
    int pos = upper_bound(numbers.begin(), numbers.end(), positions[i].second) - numbers.begin();
    int answer = 0;
    if (pos <= 0) answer = 0;
    else answer = query(pos);
    result.push_back(make_pair(positions[i].first + positions[i].second, answer));
  }
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t, ca = 1;
  scanf("%d", &t);
  while (t--) {
    Left.clear(), Right.clear();
    int n;
    scanf("%d", &n);
    REP(i, n) {
      int x, y, z, d;
      scanf("%d%d%d%d", &x, &y, &z, &d);
      if (d > 0) Right.push_back(Segment(x, y, z, d));
      else Left.push_back(Segment(x, y, z, d));
    }
    vector<pair<int, int> > answerL, answerR;
    getAnswer(Left, answerL);
    getAnswer(Right, answerR);
    //for (auto &p: answerL) {
    //  cout << "L " << p.first << ' ' << p.second << endl;
    //}
    //for (auto &p: answerR) {
    //  cout << "R " << p.first << ' ' << p.second << endl;
    //}
    int answer = 0;
    for (int i = 0; i < answerR.size(); i++) {
      answer = max(answer, answerR[i].second);
    }
    int now = 0, mx = 0;
    for (int i = 0; i < answerL.size(); i++) {
      while (now < answerR.size() && answerR[now].first <= answerL[i].first) {
        mx = max(mx, answerR[now].second);
        now++;
      }
      answer = max(answer, answerL[i].second + mx);
    }
    printf("Case #%d:\n%d\n", ca++, answer);
  }
  return 0;
}
