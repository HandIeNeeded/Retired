/*************************************************************************
	> File Name: E.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 04:00:52 PM CST
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

const int N = 1e5 + 5;
pair<int, int> p[N];
int a[N];
LL prefix[N];

bool cmp(const pair<int, int>& a, const pair<int, int> &b) {
  return (a.first < b.first) || (a.first == b.first && a.second > b.second);
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n, k, m;
  while (scanf("%d%d%d", &n, &k, &m) > 0) {
    REPP(i, 1, n) scanf("%d", a + i);
    REP(i, m) {
      int x, y;
      scanf("%d%d", &x, &y);
      p[i] = make_pair(x, y);
    }
    sort(p, p + m, cmp);
    multiset<int> left, right;
    REP(i, k) {
      left.insert(p[i].first);
      right.insert(p[i].second);
    }
    REPP(i, 1, n) prefix[i] = prefix[i - 1] + a[i];
    LL answer = 0;
    if (*left.begin() <= *right.rbegin()) {
      answer = max(answer, prefix[*right.rbegin()] - prefix[*left.begin() - 1]);
    }
    //cout << *left.rbegin() << ' ' << *right.begin() << endl;
    //REPP(i, 1, n) cout << prefix[i] << ' ';
    for (int i = k, j = 0; i < m; i++, j++) {
      multiset<int> :: iterator pos = left.find(p[j].first);
      left.erase(pos);
      left.insert(p[i].first);

      pos = right.find(p[j].second);
      right.erase(pos);
      right.insert(p[i].second);

      //cout << *left.rbegin() << ' ' << *right.begin() << endl;
      //if (*left.rbegin() <= *right.begin()) {
        //answer = max(answer, prefix[*right.begin()] - prefix[*left.rbegin() - 1]);
      answer = max(answer, prefix[*right.rbegin()] - prefix[*left.begin() - 1]);
      //}
    }
    cout << answer << endl;
    //printf("%d\n", answer);
  }
  return 0;
}

