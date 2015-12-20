#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
//SCC O(N+M)
vector<int> mp[N], g[N], s; // mp 原图邻接表 g 原图转置邻接表 原图节点从0开始标号 栈
int vis[N], sccno[N], scc_cnt; //i 所属于的SCC的标号 1--> scc_cnt，SCC数量
vector<int> edge[N];
int dp[N];

void dfs1(int x) {
    vis[x] = 1;
    REP(i, mp[x].size()) if (!vis[mp[x][i]]) dfs1(mp[x][i]);
    s.push_back(x);
}

void dfs2(int x) {
    sccno[x] = scc_cnt;
    REP(i, g[x].size()) if (!sccno[g[x][i]]) dfs2(g[x][i]);
}

void find_scc(int n) {
    scc_cnt = 0;
    s.clear();
    MST(vis, 0), MST(sccno, 0);
    REP(i, n) if (!vis[i]) dfs1(i);
    for (int i = n - 1; i >= 0; --i) {
        if (!sccno[s[i]]) {
            scc_cnt++; 
            dfs2(s[i]);
        } 
    }
}

int a[N], b[N], cnt[N], tot;
int in[N], win[N];
//1, 2, 4 win draw lose

void bfs() {
    queue<int> q;
    REPP(i, 1, tot) win[i] = 1;
    REPP(i, 1, tot) if (in[i] == 0) {
        q.push(i);
        if (dp[i] == 0) dp[i] = 4;
    }
    while (q.size()) {
        int x = q.front(); q.pop();
        //cout << "xixi: " << x << ' ' << dp[x] << endl;
        for (auto &y: edge[x]) {
            //cout << "lala" << y << endl;
            if (dp[x] != 1) {
                win[y] = 0;
            }
            if (dp[x] == 2) dp[y] |= 2;
            if (dp[x] == 4) dp[y] |= 1;
            in[y]--;
            if (in[y] == 0) {
                if (win[y]) dp[y] |= 4;
                if (dp[y] & 1) dp[y] = 1;
                else if (dp[y] & 2) dp[y] = 2;
                q.push(y);
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        a[i] = x, b[i] = y;
        mp[x].push_back(y);
        g[y].push_back(x);
    }
    find_scc(n);
    //cout << scc_cnt << endl;
    //REP(i, n) {
    //    cout << sccno[i] << ' ';
    //}
    //cout << endl;
    REP(i, n) {
        cnt[sccno[i]]++;
    }
    REP(i, n) {
        if (cnt[sccno[i]] > 1) {
            dp[sccno[i]] = 2;
        }
    }
    tot = scc_cnt;
    //REPP(i, 1, tot) {
    //    cout << cnt[i] << ' ';
    //}
    //cout << endl;
    //REPP(i, 1, tot) {
    //    cout << dp[i] << ' ';
    //}
    //cout << endl;
    REP(i, m) {
        int x = a[i], y = b[i];
        if (sccno[x] != sccno[y]) {
            edge[sccno[y]].push_back(sccno[x]);
            in[sccno[x]]++;
        }
    }
    bfs();
    //REPP(i, 1, tot) {
    //    cout << dp[i] << ' ';
    //}
    //cout << endl;
    int ans = dp[sccno[0]];
    if (ans & 1) {
        puts("Snuke");
    }
    else if (ans & 2) {
        puts("Draw");
    }
    else {
        puts("Sothe");
    }

    return 0;
}


