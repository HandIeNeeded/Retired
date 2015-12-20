#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second || (a.second == b.second && a.first > b.first);
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second > b.first + b.second;
}

const int N = 55;
pair<int ,int> p[N];

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif
    int x, y, n;
    cin >> n >> x >> y;
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        p[i] = {a,  b};
    }
    sort(p, p + n, cmp);
    int sumb = 0, sum = 0;
    int ans = 0, pos = 0;
    REP(i, n) {
        if (sumb + p[i].second >= y) break;
        ans++, pos = i;
        sumb += p[i].second;
        sum += p[i].first + p[i].second;
    }
    vector<pair<int, int>> tmp;
    REPP(i, pos + 1, n - 1) tmp.push_back(p[i]);
    sort(tmp.begin(), tmp.end(), cmp2);
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        auto now = *it;
        if (sumb + now.second >= y) {
            sumb += now.second;
            sum += now.first + now.second;
            tmp.erase(it);
            ans++;
            break;
        }
    }
    for (auto &now: tmp) {
        if (sum < x + y) {
            sum += now.first + now.second;
            ans++;
        }
    }
    assert(ans <= n);
    if (sumb < y || sum < x + y) {
        puts("-1");
        return 0;
    }
    cout << ans << endl;

    return 0;
}


