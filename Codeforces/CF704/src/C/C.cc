/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 11 Aug 2016 08:43:19 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;

vector<pair<int, int>> edges[N];
int dp[N][2][2], visited[N], marked[N];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int Sgn(int x) {
  if (x < 0) return 1;
  else return 0;
}

void Decode(int x, int &idx, int& type) {
  type = x & 3;
  idx = x >> 2;
}

int main() {
  ios :: sync_with_stdio(0);
  int n, m;
  cin >> m >> n;
  int has = 1;
  int cnt = 0, mark = 0;
  int result = 1, answer[2] = {1};
  for (int i = 0; i < m; i++) {
    int t, a[2] = {0};
    cin >> t;
    for (int j = 0; j < t; j++) cin >> a[j];
    int x = abs(a[0]), y = abs(a[1]);
    visited[x] = visited[y] = 1;
    if (t == 2) {
      if (x == y) {
        if (Sgn(a[0]) != Sgn(a[1])) {
          visited[x] = 0;
          has ^= 1;
        }
        else {
          mark = 1;
        }
      }
      else {
        int type = 0;
        for (int k = 0; k < 2; k++) type |= (1 << (Sgn(a[k])));
        int idx1 = 2 * Sgn(a[0]) + Sgn(a[1]);
        int idx2 = 2 * Sgn(a[1]) + Sgn(a[0]);
        edges[x].push_back({y, (i << 2) | idx1});
        edges[y].push_back({x, (i << 2) | idx2});
      }
    }
    else marked[x] = Sgn(a[0]) ? 2: 1;
  }
  for (int i = 1; i <= n; i++) if (visited[i] == 1 && edges[i].size() == 0) mark = 1;
  if (mark) {
    result = 1;
    for (int i = 1; i <= n - 1; i++) {
      result <<= 1;
      if (result >= MO) result -= MO;
    }
    cout << result << endl;
    return 0;
  }
  //1. unused variable
  for (int i = 1; i <= n; i++) if (!visited[i]) {
    result <<= 1;
    if (result >= MO) result -= MO;
  }
  cerr << "Step 1: " << answer[0] << ' ' << answer[1] << ' ' << result << endl;
  //1.5 start with self loop 
  for (int i = 1; i <= n; i++) if (marked[i] && visited[i] == 1) {
    int edge, type;
    visited[i] = 2;
    int result[2] = {0};
    for (int start = 0; start < 2; start++) {
      for (int a = 0; a < 2; a++) 
        for (int b = 0; b < 2; b++) 
          dp[i][a][b] = 0;
      dp[i][0][start] = 1;
      int pre = i;
      int x = edges[i][0].first;
      Decode(edges[i][0].second, edge, type);
      while (1) {
        //cout << pre << ' ' << x << endl;
        visited[x] = 2;
        for (int a = 0; a < 2; a++) 
          for (int b = 0; b < 2; b++) 
            dp[x][a][b] = 0;
        for (int now = 0; now < 2; now++) {
          for(int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
              int nn = now, nb = b;
              if (type & 2) nb ^= 1;
              if (type & 1) nn ^= 1;
              //cout << "pre: " << pre << ' ' << a << ' ' << b << ' ' << "to: " << x << ' ' << (a ^ (nb | nn)) << ' ' << now << " val: " << dp[pre][a][b] << endl;
              Add(dp[x][a ^ (nb | nn)][now], dp[pre][a][b]);
            }
          }
        }
        if (edges[x].size() == 1) break;
        pre = x;
        for (int k = 0; k < 2; k++) {
          int now, t;
          Decode(edges[x][k].second, now, t);
          if (now != edge) {
            edge = now;
            type = t;
            x = edges[x][k].first;
            break;
          }
        }
      }
      for (int sum = 0; sum < 2; sum++) {
        for (int a = 0; a < 2; a++) {
          int now = sum;
          if (marked[i] == 1) now ^= start;
          else if (marked[i] == 2) now ^= (1 ^ start);
          if (marked[x] == 1) now ^= a;
          else if (marked[x] == 2) now ^= (1 ^ a);
          Add(result[now], dp[x][sum][a]);
        }
      }
    }
    int tmp[2] = {0};
    for (int k = 0; k < 2; k++) tmp[k] = answer[k];
    for (int k = 0; k < 2; k++) {
      answer[k] = 0;
      for (int a = 0; a < 2; a++) {
        Add(answer[k], 1LL * tmp[a] * result[k ^ a] % MO);
      }
    }
  }
  cerr << "Step 1.5: " << answer[0] << ' ' << answer[1] << ' ' << result << endl;
  
  //2. start with only one edge, straight line  x <-> y <-> ... <-> z
  //dp[x][2][2] all xor result, last value
  for (int i = 1; i <= n; i++) if (visited[i] == 1 && edges[i].size() == 1u) {
    int edge, type;
    //i <-> x <-> ...
    dp[i][0][0] = dp[i][0][1] = 1;
    Decode(edges[i][0].second, edge, type);
    visited[i] = 2;
    int pre = i;
    int x = edges[i][0].first;
    while (1) {
      //dp
      visited[x] = 2;
      for (int now = 0; now < 2; now++) {
        for(int a = 0; a < 2; a++) {
          for (int b = 0; b < 2; b++) {
            int nn = now, nb = b;
            if (type & 2) nb ^= 1;
            if (type & 1) nn ^= 1;
            Add(dp[x][a ^ (nb | nn)][now], dp[pre][a][b]);
          }
        }
      }
      if (edges[x].size() == 1) break;
      //go to next node
      pre = x;
      for (int i = 0; i < 2; i++) {
        int now, t;
        Decode(edges[x][i].second, now, t);
        if(now != edge) {
          edge = now;
          type = t;
          x = edges[x][i].first;
          break;
        }
      }
    }
    int tmp[2];
    for (int k = 0; k < 2; k++) tmp[k] = answer[k];
    for (int k = 0; k < 2; k++) {
      answer[k] = 1LL * tmp[0] * (dp[x][k][0] + dp[x][k][1]) % MO;
      Add(answer[k], 1LL * tmp[1] * (dp[x][1 ^ k][0] + dp[x][1 ^ k][1]) % MO);
    }
  }
  cerr << "Step 2: " << answer[0] << ' ' << answer[1] << ' ' << result << endl;
  //3. circle
  //dp as previous
  for (int i = 1; i <= n; i++) if (visited[i] == 1 && edges[i].size() == 2u) {
    int edge, type;
    visited[i] = 2;
    int result[2] = {0};
    for (int start = 0; start < 2; start++) {
      for (int a = 0; a < 2; a++) 
        for (int b = 0; b < 2; b++) 
          dp[i][a][b] = 0;
      dp[i][0][start] = 1;
      int pre = i;
      int x = edges[i][0].first;
      Decode(edges[i][0].second, edge, type);
      while (1) {
        visited[x] = 2;
        for (int a = 0; a < 2; a++) 
          for (int b = 0; b < 2; b++) 
            dp[x][a][b] = 0;
        for (int now = 0; now < 2; now++) {
          for(int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
              int nn = now, nb = b;
              if (type & 2) nb ^= 1;
              if (type & 1) nn ^= 1;
              Add(dp[x][a ^ (nb | nn)][now], dp[pre][a][b]);
            }
          }
        }
        pre = x;
        for (int k = 0; k < 2; k++) {
          int now, t;
          Decode(edges[x][k].second, now, t);
          if (now != edge) {
            edge = now;
            type = t;
            x = edges[x][k].first;
            break;
          }
        }
        if (x == i) break;
      }
      for (int sum = 0; sum < 2; sum++) {
        for (int a = 0; a < 2; a++) {
          int nn = a, nb = start;
          if (type & 2) nn ^= 1;
          if (type & 1) nb ^= 1;
          int now = sum ^ (nn | nb);
          Add(result[now], dp[pre][sum][a]);
        }
      }
    }
    int tmp[2] = {0};
    for (int k = 0; k < 2; k++) tmp[k] = answer[k];
    for (int k = 0; k < 2; k++) {
      answer[k] = 0;
      for (int a = 0; a < 2; a++) {
        Add(answer[k], 1LL * tmp[a] * result[k ^ a] % MO);
      }
    }
  }
  cerr << "Step 3: " << answer[0] << ' ' << answer[1] << ' ' << result << endl;
  cerr << "has: " << has << endl;
  
  //Step 4, single number to make it up
  if (cnt) {
    cout << 1LL * result * (answer[0] + answer[1]) % MO << endl;
  }
  else cout << 1LL * result * answer[has] % MO << endl;
  return 0;
}
