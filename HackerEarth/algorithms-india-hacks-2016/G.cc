/*************************************************************************
	> File Name: G.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 06 Feb 2016 11:43:48 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int n, t;
    string s;
    cin >> t;
    while (t--) {
        LL ans = -1;
        int id = 0, length = 0;
        int cnt[26];
        cin >> n >> s;
        REP(i, 26) cnt[i] = 0;
        REP(i, s.size()) cnt[s[i] - 'a']++;
        REPP(i, 1, n) {
            string r;
            int f[26];
            REP(i, 26) f[i] = 0;
            cin >> r;
            REP(i, r.size()) f[r[i] - 'a']++;
            LL res = 0;
            REP(i, 26) res += 1LL * cnt[i] * f[i];
            //cout << r << ' ' << res << endl;
            if (res > ans) {
                ans = res;
                id = i;
                length = r.size();
            }
            else if (ans == res && r.size() < length) {
                id = i;
                length = r.size();
            }
        }
        cout << id << endl;
    }
    return 0;
}


