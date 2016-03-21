//O(N^3) 无向图 无负权
int vis[N], weight[N];//weight all edge weight connect i from set A
int combine[N]; //has been merged or not
int mp[N][N]; //map nodes 0based (starts from 0)

int source, sink, cut, n;

void search() {
    int Max, tmp;
    MST(vis, 0), MST(weight, 0);
    source = sink = -1;
    REP(i, n) {
        Max = -INF;
        REP(j, n) {
            if (!combine[j] && !vis[j] && weight[j] > Max) {
                tmp = j;
                Max = weight[j];
            }
        }
        if (sink == tmp) return ;
        source = sink, sink = tmp;
        cut = Max;
        vis[tmp] = 1;
        REP(j, n) {
            if (!combine[j] && !vis[j]) {
                weight[j] += mp[tmp][j];
            }
        }
    }
}

int find() {
    MST(combine, 0);
    int ans = INF;
    REP(i, n - 1) {
        search();
        if (cut < ans) ans = cut;
        if (ans == 0) return 0;
        combine[T] = 1;
        REP(j, n) if (!combine[j]) {
            mp[S][j] += mp[T][j];
            mp[j][S] += mp[j][T];
        }
    }
    return ans;
}
