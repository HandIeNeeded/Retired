/*************************************************************************
  >         File: E.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 10 Oct 2016 01:35:29 PM CST
*************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int N = 111111;
int n, q;
int tr[N * 4][26], cnt[N * 4], val[N * 4], node;

int Node(int x = 0) {
  memset(tr[node], 0, sizeof(tr[node]));
  cnt[node] = 0, val[node] = x;
  return node++;
}

void Insert(const string& s, int id) {
  int now = 0, x;
  for (int i = 0; i < (int) s.size(); ++i) {
    x = s[i] - 'a';
    if (!tr[now][x]) tr[now][x] = Node();
    now = tr[now][x];
    cnt[now]++;
  }
  val[now] = id;
}

int Ask(int node, int x, const string &order) {
  if (val[node]) x--;
  if (x == 0) return val[node];
  for (int i = 0; i < 26; ++i) {
    int son = tr[node][order[i] - 'a'];
    if (son == 0) continue;
    if (cnt[son] < x) x -= cnt[son];
    else {
      return Ask(son, x, order);
    }
  }
  return -1;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  std::ios::sync_with_stdio(0);
  std::cin >> n;
  Node();
  for (int i = 0; i < n; ++i) {
    string s;
    std::cin >> s;
    Insert(s, i + 1);
  }
  //for (int i = 0; i < 20; ++i) {
  //  std::cerr << "# i # is " << i << std::endl;
  //  std::cerr << "# cnt[i] # is " << cnt[i] << std::endl;
  //  std::cerr << "# val[i] # is " << val[i] << std::endl;
  //}
  int q;
  std::cin >> q;
  while (q--) {
    int x;
    string order;
    std::cin >> x >> order;
    std::cout << Ask(0, x, order) << std::endl;
  }
  return 0;
}
