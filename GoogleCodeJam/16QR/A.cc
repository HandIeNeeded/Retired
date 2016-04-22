/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 10 Apr 2016 12:31:27 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

    ios::sync_with_stdio(0);
    int n, t, ca = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << "Case #" << ca++ << ": ";
        if (n == 0) {
            cout << "INSOMNIA" << endl;
            continue;
        }
        else {
            bitset<10> visited;
            int ans = 0;
            while (!visited.all()) {
                ans += n;
                string str = to_string(ans);
                REP(i, str.size()) visited.set(str[i] - '0');
            }
            cout << ans << endl;
        }
    }

    return 0;
}

