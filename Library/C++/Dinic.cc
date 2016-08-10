template<int NODE, int EDGE, typename Type, Type INF>
class MaxFlow {
public:
  int edge, source, sink;
  int level[NODE], current[NODE];
  int first[NODE], next[EDGE << 1], to[EDGE << 1];
  Type cap[EDGE << 1];

  void Init(int S, int T) {
    source = S, sink = T;
    edge = 1, memset(first, 0, sizeof(first));
  }

  void add(int x, int y, Type z) {
    next[++edge] = first[x]; first[x] = edge; 
    to[edge] = y; cap[edge] = z;
  }

  void Add(int x, int y, Type z) {
    add(x, y, z);
    add(y, x, 0);
  }

  Type Dinic() {
    Type ans = 0;
    while (Bfs()) {
      memcpy(current, first, sizeof(first));
      ans += Dfs(source, INF);
    }	
    return ans;
  }

private:
  bool Bfs() {
    queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(source), level[source] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (int go = first[x]; go; go = next[go]) if (cap[go] > 0 && !level[to[go]]) {
        int y = to[go];
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
    return level[sink];
  }

  Type Dfs(int x, Type flow) {
    if (x == sink || flow == 0) return flow;
    Type ans = 0, tmp;
    for (int &go = current[x]; go; go = next[go]) if (cap[go] > 0) {
      int y = to[go];
      if (level[y] == level[x] + 1 && (tmp = Dfs(y, min(flow, cap[go]))) > 0) {
        ans += tmp, flow -= tmp;
        cap[go] -= tmp, cap[go ^ 1] += tmp;
        if (flow == 0) break;
      }
    }
    return ans;
  }
};
