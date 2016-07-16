struct Automation{
  int tr[N][Z], fail[N], val[N], node;

  int Node() {
    memset(tr[node], 0, sizeof(tr[node]));
    fail[node] = 0;
    return node++;
  }

  void Init() {
    node = 0;
    Node();
  }

  void Insert(char *s, int y) {
    int pos = 0, x, now = 0;
    while (s[pos]) {
      x = s[pos++] - 'a';
      if (!tr[now][x]) {
        tr[now][x] = Node();
      }
      now = tr[now][x];
    }
    val[now] = y;
  }

  void Build() {
    int x, y;
    queue<int> q;
    REP(i, Z) {
      x = tr[0][i];
      if (x) {
        fail[x] = 0;
        q.push(x);
      }
    }

    while (!q.empty()) {
      x = q.front(); q.pop();
      REP(i, Z) {
        if (!tr[x][i]) {
          tr[x][i] = tr[fail[x]][i];
          continue;
        }
        y = tr[x][i];
        q.push(y);
        fail[y] = tr[fail[x]][i];
        val[y] += val[fail[y]];
      }
    }
  }
}AC;

