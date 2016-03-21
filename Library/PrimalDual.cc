struct MCF{
    int fi[N], en[M << 1], ne[M << 1], cost[M << 1], cap[M << 1], edge;
    int dis[N], vis[N], source, sink, per;
    const int inf = 0x3f3f3f3f;
    
    void init(int S, int T) {
        source = S, sink = T, per = 0;
        memset(fi, 0, sizeof(fi)), edge = 1;
    }

    void _add(int x, int y, int z, int w) {
        ne[++edge] = fi[x], en[edge] = y, fi[x] = edge, cap[edge] = z, cost[edge] = w;
    }

    void add(int x, int y, int z, int w) {
        _add(x, y, z, w);
        _add(y, x, 0, -w);
    }

    pair<int, int> aug(int x, int flow) {
        if (x == sink) {
            return {per * flow, flow};
        }
        vis[x] = 1;
        int tmp = flow;
        for (int go = fi[x]; go; go = ne[go]) {
            int y = en[go];
            if (cap[go] && !cost[go] && !vis[y]) {
                int d = aug(y, tmp < cap[go] ? tmp : cap[go]).second;
                cap[go] -= d, cap[go ^ 1] += d, tmp -= d;
                if (!tmp) return {0, flow};
            }
        }
        return {0, flow - tmp};
    }

    int modLable() {
        memset(dis, 0x3f, sizeof(dis));
        deque<int> q;
        dis[sink] = 0, q.push_back(sink);
        while (q.size()) {
            int dist, x = q.front(); q.pop_front();
            for (int go = fi[x]; go; go = ne[go]) {
                int y = en[go];
                if (cap[go ^ 1] && (dist = dis[x] - cost[go]) < dis[y]) {
                    dis[y] = dist;
                    int x = q.size() ? q.front() : 0;
                    if (dis[y] <= dis[x]) {
                        q.push_front(y);
                    }
                    else {
                        q.push_back(y);
                    }
                }
            }
        }
        REP(i, sink + 1) {
            for (int go = fi[i]; go; go = ne[go]) {
                int y = en[go];
                cap[go] += dis[y] - dis[i];
            }
        }
        per += dis[source];
        return dis[source] < inf;
    }

    pair<int, int> minCost() {
        int flow = 0, cost = 0;
        while (modLable()) {
            memset(vis, 0, sizeof(vis));
            int x, y;
            tie(x, y) = aug(source, inf);
            cost += x, flow += y;
        }
        return {cost, flow};
    }
}flow;

