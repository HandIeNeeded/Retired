/*************************************************************************
	> File Name: B2.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 10 Apr 2016 02:49:27 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

bool dfs(int now, int depth, string str) {
    if (now == depth) return str.find('-') == string::npos;
    else {
        REP(i, str.size()) {
            string tmp = str;
            reverse(tmp.begin(), tmp.begin() + i + 1);
            REP(j, i + 1) tmp[j] = '-' + '+' - tmp[j];
            if (dfs(now + 1, depth, tmp)) return true;
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
    int t, ca = 1;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << "Case #" << ca++ << ": ";
        REP(limit, 100) {
            if (dfs(0, limit, str)) {
                cout << limit << endl;
                break;
            }
        }
    }
    return 0;
}

