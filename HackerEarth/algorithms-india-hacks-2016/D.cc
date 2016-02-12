/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 07 Feb 2016 02:30:34 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

vector<string> mp;
vector<vector<int>> color, vis;

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        mp.clear(), color.clear();
        mp.assign(n, "");
        color.assign(n, vector<int> ());
        REP(i, n) color[i].assign(m, 0);
        vis = color;
        int good = 1, tot = n * m;
        queue<int> q;
        REP(i, n) q.push(i), q.push(0), q.push(1 << (mp[i][0] - 'a'));
        REP(i, n) q.push(i), q.push(m - 1), q.push(1 << (mp[i][m - 1] - 'a'));
        REP(i, m) q.push(0), q.push(i), q.push(1 << (mp[0][i] - 'a'));
        REP(i, m) q.push(n - 1), q.push(i), q.push(1 << (mp[n - 1][i] - 'a'));
        
        good ? puts("YES") : puts("NO");
    }
    return 0;
}


