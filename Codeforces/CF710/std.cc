/*************************************************************************
  >         File: std.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 22 Aug 2016 11:51:48 PM CST
 *************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
const int N = 3e5 + 5;
const int Z = 26;
const int K = 555;

struct Automation{
  int tr[N][Z], fail[N], val[N], cnt[N],  node;
  bool has[N][Z];

  int Node() {
    memset(tr[node], 0, sizeof(tr[node]));
    memset(has[node], 0, sizeof(has[node]));
    fail[node] = val[node] = cnt[node] = 0;
    return node++;
  }

  void Init() {
    node = 0;
    Node();
  }

  void Insert(const char *s, int y) {
    int pos = 0, x, now = 0;
    while (s[pos]) {
      x = s[pos++] - 'a';
      if (!has[now][x]) {
        has[now][x] = 1;
        tr[now][x] = Node();
      }
      now = tr[now][x];
    }
    val[now] += y;
  }

  void Build() {
    int x, y;
    std::queue<int> q;
    for (int i = 0; i < Z; i++) {
      if (has[0][i]) {
        x = tr[0][i];
        fail[x] = 0;
        cnt[x] = val[x];
        q.push(x);
      }
    }

    while (!q.empty()) {
      x = q.front(); q.pop();
      for (int i = 0; i < Z; i++) {
        if (!has[x][i]) {
          tr[x][i] = tr[fail[x]][i];
          continue;
        }
        y = tr[x][i];
        q.push(y);
        fail[y] = tr[fail[x]][i];
        cnt[y] = val[y] + cnt[fail[y]];
      }
    }
  }

  LL Query(const char *s) {
    LL cnt = 0;
    int now = 0, pos = 0;;
    while (s[pos]) {
      int x = s[pos++] - 'a';
      now = tr[now][x];
      cnt += this->cnt[now];
    }
    return cnt;
  }
}buf, heap;

void dfs(int x, int y) { //buf heap
  for (int i = 0; i < Z; i++) if (buf.has[x][i]) {
    if (!heap.has[y][i]) {
      heap.has[y][i] = 1;
      heap.tr[y][i] = heap.Node();
    }
    int a = heap.tr[y][i], b = buf.tr[x][i];
    heap.val[a] += buf.val[b];
    dfs(b, a);
  }
}

void Merge() {
  dfs(0, 0);
  heap.Build();
  buf.Init();
}

void Init() {
  buf.Init();
  heap.Init();
}

char s[N];

int main(){
  Init();
  LL answer = 0;
  int n;
  std::cin >> n;
  while (n--) {
    int type;
    std::cin >> type >> s;
    if (type != 3) {
      int v = type == 1 ? 1 : -1;
      buf.Insert(s, v);
      if (buf.node >= K) {
        Merge();
      } else {
        buf.Build();
      }
    } else {
      answer = buf.Query(s) + heap.Query(s);
      std::cout << answer << std::endl;
      std::cout.flush();
    }
  }
  return 0;
}
