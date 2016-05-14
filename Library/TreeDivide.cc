struct Edge{
  int dist, next, end;
}e[M];

int endge, head[N], start[N];

void add(int x, int y) {
  e[++endge].next = head[x];
  head[x] = endge;
  e[endge].end = y;
}

void add(int x, int y, int z) {
  e[++endge].next = start[x];
  start[x] = endge;
  e[endge].end = y;
  e[endge].dist = z;
}

int n, m;
int vis[N], size[N], maxsub[N], root;
int dist[N];

void dfsSize(int x, int p = 0) {
  size[x] = 1, maxsub[x] = 0;
  for (int go = head[x]; go; go = e[go].next) {
    int y = e[go].end;
    if (y != p && !vis[y]) {
      dfsSize(y, x);
      size[x] += size[y];
      if (size[y] > maxsub[x]) maxsub[x] = size[y];
    }
  }
}

void dfsRoot(int x, int tot, int p = 0) {
  if (tot - size[x] > maxsub[x]) maxsub[x] = tot - size[x];
  if (maxsub[x] < maxsub[0]) maxsub[0] = maxsub[x], root = x;
  for (int go = head[x]; go; go = e[go].next) {
    int y = e[go].end;
    if (y != p && !vis[y]) {
      dfsRoot(y, tot, x);
    }
  }
}

void dfsDist(int x, int p = 0, int dep = 0) {
  add(x, root, dep);
  for (int go = head[x]; go; go = e[go].next) {
    int y = e[go].end;
    if (!vis[y] && y != p) {
      dfsDist(y, x, dep + 1);
    }
  }
}

void divide(int x) {
  maxsub[0] = N;
  dfsSize(x);
  dfsRoot(x, size[x]);
  dfsDist(root);
  vis[root] = 1;
  for (int go = head[root]; go; go = e[go].next) {
    int y = e[go].end;
    if (!vis[y]) divide(y);
  }
}
