/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 04:48:42 PM CST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

int ans, n, q;
string str[40], rep[40];

bool check(string s) {
    while (s.size() > 1) {
        string prefix = s.substr(0, 2), suffix = s.substr(2);
        //cout << prefix << ' ' << suffix << endl;
        int find = 0;
        REP(i, q) if (prefix == str[i]) {
            find = 1;
            s = rep[i] + suffix;
            break;
        }
        if (!find) return 0;
    }
    return s == "a";
}

void dfs(int dep, string now) {
    if (dep == n) {
        if (check(now)) ans++;
    }
    else {
        REP(i, 6) {
            now += 'a' + i;
            dfs(dep + 1, now);
            now.pop_back();
        }
    }
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    cin >> n >> q;
    REP(i, q) cin >> str[i] >> rep[i];
    string now;
    dfs(0, now);
    cout << ans << endl;



    return 0;
}

