/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 10 Jan 2016 12:55:45 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 2006;
int n;
pair<int, int> p[N];

LL sqr(int x) {
    return 1LL * x * x;
}

int get(int x) {
    return x * (x - 1) / 2;
}

int calc(int x) {
    unordered_map<LL, int> mp;
    REPP(i, 1, n) if (i != x) {
        mp[sqr(p[x].first - p[i].first) + sqr(p[x].second - p[i].second)]++;
    }
    int ans = 0;
    for (auto &x: mp) {
        ans += get(x.second);
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int t, ca = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        REPP(i, 1, n) {
            int x, y;
            cin >> x >> y;
            p[i] = make_pair(x, y);
        }
        LL ans = 0;
        REPP(i, 1, n) ans += calc(i);
        cout << "Case #" << ca++ << ": " << ans << endl;
    }
    return 0;
}


