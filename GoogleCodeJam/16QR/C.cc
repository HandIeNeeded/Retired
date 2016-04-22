/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 10 Apr 2016 02:17:13 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int test(LL x) {
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) return i;
    }
    return 0;
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
        int n, m;
        cin >> n >> m;
        int now = n - 2;
        cout << "Case #" << ca++ << ":" << endl;
        REP(i, 1 << now) {
            if (!m) break;
            string str;
            REP(j, now) str += '0' + (i >> j & 1);
            str = '1' + str + '1';
            bool good = 1;
            vector<int> answer;
            REPP(base, 2, 10) {
                string::size_type pos = 0;
                LL number = stoll(str, &pos, base);
                answer.push_back(test(number));
                if (!answer.back()) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                //cout << str << endl;
                cout << str << ' ';
                for (int i = 0; i < answer.size(); i++) {
                    cout << answer[i] << " \n"[i == answer.size() - 1];
                }
                m--;
            }
        }
    }

    return 0;
}

