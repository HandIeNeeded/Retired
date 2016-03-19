/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 12:39:57 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 1e5 + 5;
int A[N], B[N];
int n, m;
int in[N];
vector<int> edge[N];

bool check(int round) {
    REPP(i, 1, n) in[i] = 0, edge[i].clear();
    REPP(i, 1, round) {
        in[B[i]]++;
        edge[A[i]].push_back(B[i]);
    }
    queue<int> q;
    REPP(i, 1, n) if (in[i] == 0) {
        q.push(i);
    }
    while (q.size()) {
        if (q.size() > 1) return 0;
        int x = q.front();
        q.pop();
        for (auto &y: edge[x]) {
            in[y]--;
            if (in[y] == 0) {
                q.push(y);
            }
        }
    }
    return 1;
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin >> n >> m;
    REPP(i, 1, m) cin >> A[i] >> B[i];
    if (!check(m)) {
        cout << "-1" << endl;
    }
    else {
        int lo = 0, hi = m;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                hi = mid;
            }
            else lo = mid;
        }
        cout << hi << endl;
    }
    return 0;
}


