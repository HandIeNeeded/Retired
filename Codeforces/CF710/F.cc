/*************************************************************************
  >         File: F.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 22 Aug 2016 10:29:40 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
const int N = 3e5 + 5;
const int Z = 26;
const int K = 555;

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

  void Insert(const char *s, int y = 1) {
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
    std::queue<int> q;
    for (int i = 0; i < Z; i++) {
      x = tr[0][i];
      if (x) {
        fail[x] = 0;
        q.push(x);
      }
    }

    while (!q.empty()) {
      x = q.front(); q.pop();
      for (int i = 0; i < Z; i++) {
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

  LL Query(const char *s) {
    LL cnt = 0;
    int now = 0, pos = 0;;
    while (s[pos]) {
      int x = s[pos++] - 'a';
      now = tr[now][x];
      cnt += val[now];
    }
    return cnt;
  }
}AC;

std::unordered_set<std::string> shortStrs, longStrs;

void Add(const std::string &s) {
  if (s.size() <= K) {
    shortStrs.insert(s);
  } else {
    longStrs.insert(s);
    AC.Init();
    for (const auto &s: longStrs) {
      AC.Insert(s.c_str());
    }
    AC.Build();
  }
}

void Erase(const std::string &s) {
  if (s.size() <= K) {
    shortStrs.erase(s);
  } else {
    longStrs.erase(s);
    AC.Init();
    for (const auto &s: longStrs) {
      AC.Insert(s.c_str());
    }
    AC.Build();
  }
}

LL Ask(const std::string &s) {
  LL cnt = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    for (int j = 1; j <= K; j++) {
      if (i + j > (int) s.size()) break;
      if (shortStrs.count(s.substr(i, j))) {
        cnt++;
      }
    }
  }
  if (s.size() > K) {
    cnt += AC.Query(s.c_str());
  }
  return cnt;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int type;
    std::string s;
    std::cin >> type >> s;
    if (type == 1) Add(s);
    else if (type == 2) Erase(s);
    else {
      std::cout << Ask(s) << std::endl;
      std::cout.flush();
    }
  }
  return 0;
}
