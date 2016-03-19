/*************************************************************************
	> File Name: F.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 02:05:39 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 1e6 + 5;
const int MO = 1e9 + 7;

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int p[N], inv[N], mobius[N], fac[N], vis[N], tot;
vector<int> factor[N];

void prime() {
    factor[1].push_back(1);
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            p[tot++] = i;
            mobius[i] = MO - 1;
            factor[i].push_back(i);
        }
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            mobius[i * p[j]] = (MO - mobius[i]) % MO;
            factor[i * p[j]] = factor[i];
            factor[i * p[j]].push_back(p[j]);
            if (i % p[j] == 0) {
                mobius[i * p[j]] = 0;
                factor[i * p[j]].pop_back();
                break;
            }
        }
    }

    inv[0] = 1, inv[1] = 1, fac[0] = 1;
    REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
    REPP(i, 2, N - 1) inv[i] = 1LL * (MO - MO / i) * inv[MO % i] % MO;
}

int n, k, q;

int C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return 1LL * fac[a] * inv[b] % MO * inv[a - b] % MO;
}

int cnt[N];

void dfs(int x, int& ans, int now, int dep) {
    if (dep == factor[x].size()) {
        add(ans, MO - 1LL * x / now * C(cnt[now], k) % MO);
        cnt[now]++;
        add(ans, 1LL * x / now * C(cnt[now], k) % MO);
        return ;
    }
    else {
        dfs(x, ans, now, dep + 1);
        dfs(x, ans, now * factor[x][dep], dep + 1);
    }
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    ios::sync_with_stdio(0);
    prime();
    //REPP(i, 1, 20) {
    //    cout << i << ' ' << mobius[i] << endl;
    //    cout << i << ' ' << fac[i] << endl;
    //    cout << i << ' ' << inv[i] << endl;
    //}
    cin >> n >> k >> q;
    REPP(i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            cnt[i] += cnt[j];
        }
    }
    //cout << "hehe" << endl;
    int ans = 0;
    REPP(i, 1, N - 1) {
        if (mobius[i] == 0) continue;
        if (cnt[i] < k) continue;
        add(ans, 1LL * C(cnt[i], k) * i % MO);
    }
    while (q--) {
        int x;
        cin >> x;
        int res = 0;
        dfs(x, res, 1, 0);
        add(ans, res);
        cout << ans << endl;
    }



    return 0;
}


