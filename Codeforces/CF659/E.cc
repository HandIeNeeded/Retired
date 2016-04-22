/*************************************************************************
	> File Name: E.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Thu 31 Mar 2016 12:25:50 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int n, m;
const int N = 1e5 + 5;
bool vis[N];
vector<int> edge[N];

bool IsTree(const vector<int>& nodes) {
    int degree = 0;
    for (auto &x: nodes) {
        degree += edge[x].size();
    }
    return degree == 2 * nodes.size() - 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int cnt = 0;
    REPP(i, 1, n) if (!vis[i]) {
        queue<int> q;
        vector<int> nodes;
        vis[i] = 1, q.push(i), nodes.push_back(i);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (auto &y: edge[x]) if (!vis[y]) {
                vis[y] = 1;
                q.push(y), nodes.push_back(y);
            }
        }
        if (IsTree(nodes)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}


