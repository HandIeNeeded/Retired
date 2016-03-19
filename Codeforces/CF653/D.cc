/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 05:00:49 PM CST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

const double eps = 1e-9;

int sign(double x) {
    if (fabs(x) < eps) return 0;
    else if (x > 0) return 1;
    else return -1;
}

template<int N, int M, typename Type>
struct MaxFlow{
    int edge, source, sink;
    int lvl[N], cur[N];
    int fi[N], ne[M << 1], en[M << 1];
    Type cap[M << 1];
    const Type INF = 1LL << 60;

    void init(int S, int T) {
        source = S, sink = T;
        edge = 1, MST(fi, 0);
    }

    void _add(int x, int y, Type z) {
        ne[++edge] = fi[x]; fi[x] = edge; en[edge] = y; cap[edge] = z;
    }

    void add(int x, int y, Type z) {
        _add(x, y, z);
        _add(y, x, 0);
    }

    bool bfs() {
        queue<int> q;
        MST(lvl, 0);
        q.push(source), lvl[source] = 1;
        while(q.size()) {
            int x = q.front(); q.pop();
            for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !lvl[en[go]]) {
                int y = en[go];
                lvl[y] = lvl[x] + 1;
                q.push(y);
            }
        }
        return lvl[sink];
    }

    Type dfs(Type x, Type flow) {
        if (x == sink || flow == 0) {
            return flow;
        }
        Type ans = 0, tmp = 0;
        for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
            int y = en[go];
            if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, (Type) cap[go]))) > 0) {
                ans += tmp, flow -= tmp;
                cap[go] -= tmp, cap[go ^ 1] += tmp;
                if (flow == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }

    Type dinic() {
        Type ans = 0;
        while (bfs()) {
            memcpy(cur, fi, sizeof(fi));
            ans += dfs(source, INF);
        }	
        return ans;
    }
};
MaxFlow<500, 5000, LL> flow;

const int N = 1000;
int a[N], b[N], c[N], n, k, m;

bool check(double x) {
    flow.init(1, n);
    REP(i, m) {
        LL num = c[i] / x;
        if (sign(c[i] - (num + 1) * x) >= 0) num++;
        if (sign(c[i] - num * x) < 0) num--;
        num = max(num, 0LL);
        flow.add(a[i], b[i], num);
    }
    return flow.dinic() >= k;
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    REP(i, m) {
        cin >> a[i] >> b[i] >> c[i];
    }
    double lo = 0, hi = 2000000;
    REP(i, 60) {
        double mid = (lo + hi) / 2.0;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(10) << k * lo << endl;
    return 0;
}

