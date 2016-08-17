template<int N, int E, typename Type, Type INF>
class MaxFlow {
public:
  int edge, node, bridge, src, dst, source, sink;
  int level[N], current[N];
  int first[N], next[E << 1], to[E << 1];
  Type cap[E << 1], hasTo;

  int Node() { return node++; }

  void Init() {
    node = 4, edge = 1;
    hasTo = src = 0, dst = 1, source = 2, sink = 3;
    memset(first, 0, sizeof(first));
    bridge = Add(sink, source, INF);
  }

  int add(int x, int y, Type z) {
    next[++edge] = first[x]; first[x] = edge; 
    to[edge] = y; cap[edge] = z;
    return edge;
  }

  int Add(int x, int y, Type z) {
    add(y, x, 0);
    return add(x, y, z);
  }

  void LRAdd(int x, int y, Type L, Type R) {
    if (L == 0) Add(x, y, R);
    else {
      hasTo += L;
      Add(src, y, L);
      Add(x, dst, L);
      Add(x, y, R - L);
    }
  }

  Type Dinic() {
    while (Bfs(src, dst)) Dfs(src, dst, INF);
    if (hasTo != GetFlow(src)) return -1;

    while (Bfs(source, sink)) Dfs(source, sink, INF);
    return GetFlow(source);
  }

private:
  Type GetFlow(int x) {
    Type ans = 0;
    for (int go = first[x]; go; go = next[go]) if ((go ^ 1) != bridge) ans += cap[go ^ 1];
    return ans;
  }

  bool Bfs(int source, int sink) {
    std::queue<int> q;
    std::fill(level, level + node, 0);
    q.push(source), level[source] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (int go = current[x] = first[x]; go; go = next[go]) if (cap[go] > 0 && !level[to[go]]) {
        int y = to[go];
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
    return level[sink];
  }

  Type Dfs(int x, int sink, Type flow) {
    if (x == sink || flow == 0) return flow;
    Type ans = 0, tmp;
    for (int &go = current[x]; go; go = next[go]) if (cap[go] > 0) {
      int y = to[go];
      if (level[y] == level[x] + 1 && (tmp = Dfs(y, sink, min(flow, cap[go]))) > 0) {
        ans += tmp, flow -= tmp;
        cap[go] -= tmp, cap[go ^ 1] += tmp;
        if (flow == 0) break;
      }
    }
    return ans;
  }
};

MaxFlow<N, N, int, 1 << 30> net;
