template<int N, int M, typename Type>
struct MaxFlow{
  int edge, source, sink;
  int level[N], current[N];
  int first[N], next[M << 1], end[M << 1];
  Type cap[M << 1];
  const Type INF = ;

  void Init(int S, int T) {
    source = S, sink = T;
    edge = 1, memset(first, 0, sizeof(first));
  }

  void add(int x, int y, Type z) {
    next[++edge] = first[x]; first[x] = edge; end[edge] = y; cap[edge] = z;
  }

  void Add(int x, int y, Type z) {
    add(x, y, z);
    add(y, x, 0);
  }

  bool Bfs() {
    queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(source), level[source] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (int go = first[x]; go; go = next[go]) if (cap[go] > 0 && !level[end[go]]) {
        int y = end[go];
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
    return level[sink];
  }

  Type Dfs(Type x, Type flow) {
    if (x == sink || flow == 0) {
      return flow;
    }
    Type ans = 0, tmp = 0;
    for (int &go = current[x]; go; go = next[go]) if (cap[go] > 0) {
      int y = end[go];
      if (level[y] == level[x] + 1 && (tmp = Dfs(y, min(flow, (Type) cap[go]))) > 0) {
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
    while (Bfs()) {
      memcpy(current, first, sizeof(first));
      ans += Dfs(source, INF);
    }	
    return ans;
  }
};
MaxFlow<10000, 10000, int> flow;
