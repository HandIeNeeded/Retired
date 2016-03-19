#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

bool check(string s) {
    if (s.size() & 1) return 0;
    int now = 0;
    REP(i, s.size()) {
        if (s[i] == '(') now++;
        else now--;
        if (now < 0) return 0;
    }
    return now == 0;
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    set<string> good;
    int n;
    string s;
    cin >> n >> s;
    REP(i, n) {
        REPP(j, i + 1, n - 1) {
            string tmp = s.substr(i, j - i + 1);
            if (check(tmp)) good.insert(tmp);
        }
    }
    cout << good.size() << endl;
    return 0;
}

