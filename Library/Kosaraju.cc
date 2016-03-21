//SCC O(N+M)
vector<int> mp[N], g[N], s; // mp 原图邻接表 g 原图转置邻接表 原图节点从0开始标号 栈
int vis[N], label[N], cnt; //i 所属于的SCC的标号 1--> cnt，SCC数量

void DFS1(int x) {
    vis[x] = 1;
    REP(i, mp[x].size()) if (!vis[mp[x][i]]) DFS1(mp[x][i]);
    s.push_back(x);
}

void DFS2(int x) {
    label[x] = cnt;
    REP(i, g[x].size()) if (!label[g[x][i]]) DFS2(g[x][i]);
}

void Kosaraju(int n) {
    cnt = 0;
    s.clear();
    MST(vis, 0), MST(label, 0);
    REP(i, n) if (!vis[i]) DFS1(i);
    for (int i = n - 1; i >= 0; --i) {
        if (!label[s[i]]) {
            cnt++; 
            DFS2(s[i]);
        } 
    }
}
