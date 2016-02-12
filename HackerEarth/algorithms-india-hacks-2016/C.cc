/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 06 Feb 2016 05:21:16 PM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

vector<vector<int>> cnt;
vector<string> mp;
int n, m, dx[] = {0, 1}, dy[] = {1, 0};

bool good(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void expand(int x, int y) {
    REP(i, 2) {
        int tx = x + dx[i], ty = y + dy[i];
        if (!good(tx, ty)) continue;
        if (mp[x][y] != mp[tx][ty]) {
            //cout << x << ' ' << y << ' ' << tx << ' ' << ty << "diff" << endl;
            if (i == 0) cnt[x][y + 1]++, cnt[x  + 1][y + 1]++;
            if (i == 1) cnt[x + 1][y]++, cnt[x + 1][y + 1]++;
        }
    }
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    ios :: sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        mp.assign(n, "");
        REP(i, n) cin >> mp[i];
        //REP(i, n) {
        //    cout << mp[i] << endl;
        //}
        cnt.clear();
        cnt.assign(n + 1, vector<int> ());
        REP(i, n + 1) cnt[i].assign(m + 1, 0);
        //REP(i, n + 1) {
        //    REP(j, m + 1) {
        //        cout << cnt[i][j] << ' ';
        //    }
        //    cout << endl;
        //}
        REP(i, n) REP(j, m) expand(i, j);
        //REP(i, n + 1) {
        //    REP(j, m + 1) {
        //        cout << cnt[i][j] << ' ';
        //    }
        //    cout << endl;
        //}
        int ans =  0;
        REP(i, n + 1) REP(j, m + 1) if (cnt[i][j] & 1) ans++;
        cout << ans / 2 << endl;
    }
    return 0;
}

