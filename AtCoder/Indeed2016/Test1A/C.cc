/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 07:27:37 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int MAX_NODES = 105;

bool graphs[MAX_NODES][MAX_NODES];
int distanceFromStart[MAX_NODES];
int nodesCount, queryCount;
bitset<MAX_NODES> visitedMark;

int GetShortestPath(int start, int end) {
  REPP(i, 1, nodesCount) distanceFromStart[i] = INT_MAX;
  visitedMark.reset();
  queue<int> que;
  que.push(start), visitedMark.set(start), distanceFromStart[start] = 0;
  while (que.size()) {
    int nowNode = que.front(); que.pop();
    visitedMark.reset(nowNode);
    REPP(nextNode, 1, nodesCount) if (graphs[nowNode][nextNode]) {
      if (distanceFromStart[nextNode] > distanceFromStart[nowNode] + 1) {
        distanceFromStart[nextNode] = distanceFromStart[nowNode] + 1;
        que.push(nextNode);
        visitedMark.set(nextNode);
      }
    }
  }
  if (distanceFromStart[end] == INT_MAX) distanceFromStart[end] = -1;
  return distanceFromStart[end];
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  cin >> nodesCount >> queryCount;
  REPP(i, 1, nodesCount - 1) graphs[i][i + 1] = 1;
  while (queryCount--) {
    int a, b;
    cin >> a >> b;
    cout << GetShortestPath(a, b) << endl;
    graphs[a][b] = 1;
  }
  return 0;
}


