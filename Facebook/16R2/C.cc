/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 24 Jan 2016 03:14:25 AM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define ALL(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
pair<int, int> p[N];
int mx[N << 2], a[N];
vector<int> numx, numy;
vector<int> pos[N];
int ql, qr;

void build(int x, int l, int r) {
    if (l == r) {
        mx[x] = a[l];
    }
    else {
        build(LC), build(RC);
        mx[x] = max(mx[L], mx[R]);
    }
}

int query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return mx[x];
    }
    else {
        int a = 0, b = 0;
        if (ql <= MID) a = query(LC);
        if (qr > MID) b = query(RC);
        return max(a, b);
    }
}

const int MO = 1e9 + 7;

int pow(int x) {
    return 1LL * x * x % MO;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int sqr[N], sum[N], cnt[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, numy.size()) pos[i].clear();
        numx.clear(), numy.clear();
        REPP(i, 1, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            p[i] = {x, y};
            numx.push_back(x);
            numy.push_back(y);
        }
        REPP(i, 1, n) sqr[i] = sum[i] = cnt[i] = 0;
        
        sort(ALL(numx));
        numx.resize(unique(ALL(numx)) - numx.begin());
        sort(ALL(numy));
        numy.resize(unique(ALL(numy)) - numy.begin());
        REPP(i, 1, n) {
            p[i].first = lower_bound(ALL(numx), p[i].first) - numx.begin() + 1;
            p[i].second = lower_bound(ALL(numy), p[i].second) - numy.begin() + 1;
        }
        sort(p + 1, p + n + 1);
        REPP(i, 1, n) {
            pos[p[i].second].push_back(p[i].first);
        }
        REPP(i, 1, n) a[i] = p[i].second;
        int tot = numx.size();
        build(1, 1, tot);
        int ans = 0;
        REPP(i, 1, numy.size()) {
            if (pos[i].size() > 1) {
                for (int j = 0; j < int(pos[i].size()); j++) {
                    int x = pos[i][j], y, dx;
                    if (j == 0) {
                        cnt[x] = sqr[x] = sum[x] = 0;
                    }
                    else {
                        y = pos[i][j - 1];
                        ql = y, qr = x;
                        int mx = query(1, 1, tot);
                        if (mx <= i) {
                            dx = numx[x - 1] - numx[y - 1];
                            cnt[x] = cnt[y] + 1;
                            sum[x] = sum[y];
                            add(sum[x], 1LL * (cnt[y] + 1) * dx % MO);
                            sqr[x] = 0;
                            add(sqr[x], sqr[y]);
                            add(sqr[x], 2LL * sum[y] * dx % MO);
                            add(sqr[x], 1LL * (cnt[y] + 1) * pow(dx) % MO);
                            add(ans, sqr[x]);
                        }
                        else {
                            sqr[x] = cnt[x] = sum[x] = 0;
                        }
                    }
                }
            }
        }
        //REPP(i, 1, n) {
        //    cout << cnt[i] << ' ' << sqr[i] << ' ' << sum[i] << endl;
        //}
        printf("Case #%d: %d\n", ca++, ans);
    }


    return 0;
}

