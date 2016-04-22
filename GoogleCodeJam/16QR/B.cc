/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 10 Apr 2016 12:42:27 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

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
        int ans = 0;
        while (str.find('-') != string::npos) {
            int pos = str.find_last_of('-');
            ans++;
            reverse(str.begin(), str.begin() + pos + 1);
            REP(i, pos + 1) str[i] = '-' + '+' - str[i];
            if (str[pos] != '+') {
                ans++;
                str[pos] = '+';
            }
        }
        cout << ans << endl;
    }

    return 0;
}

