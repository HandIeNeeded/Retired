/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 30 Jan 2016 02:21:14 AM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 2e5 + 5;
int cnt[N];
template<int N, int M, typename Type>
struct MaxFlow{
    int edge, source, sink;
    int lvl[N], cur[N];
    int fi[N], ne[M << 1], en[M << 1];
    Type cap[M << 1];
    const Type INF = 0x3f3f3f3f;

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
MaxFlow<N, 2 * N, int> flow;

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    int n, A, B;
    scanf("%d", &n);
    scanf("%d%d", &A, &B);
    REPP(i, 1, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        cnt[x]++, cnt[y]++;
    }
    if (A > B) {
        int mx = *max_element(cnt + 1, cnt + n + 1);
        if (mx == n - 1) {
            cout << 1LL * A + (n - 2LL) * B << endl;
        }
        else {
            cout << (n - 1LL) * B << endl;
        }
    }
    else {
        int mA = *max_element(cnt + 1, cnt + n + 1);
        int ans = mA - 1;
        cout << (ans - 1LL) * B + 1LL * (n - ans) * A << endl;
    }
    return 0;
}

