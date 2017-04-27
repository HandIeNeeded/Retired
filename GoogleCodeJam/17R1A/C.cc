/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr 15 11:28:01 2017
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

constexpr int N = 101;
int dp[2][N][N][N];

void toMin(int &x, int y) {
  if (x > y) x = y;
}

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          for (int t = 0; t < N; ++t) {
            dp[i][j][k][t] = N;
          }
        }
      }
    }
    int hd, ad, hk, ak;
    int B, D;
    int HP;
    std::cin >> hd >> ad >> hk >> ak;
    std::cin >> B >> D;
    HP = hd;
    //[turn][hp_dragon][atk_dragon][atk_knight]
    dp[0][hd][ad][ak] = hk;
    int cur = 0;
    std::cout << "Case #" << cas << ": ";
    bool bad = 0;
    int ans = 0;
    for (int turn = 1; turn < 4 * N; ++turn) {
      bool noValid = 1;
      int next = cur ^ 1;
      bool isFinish = 0;
      for (int hd = 1; hd < N; ++hd) {
        for (int ad = 1; ad < N; ++ad) {
          for (int ak = 0; ak < N; ++ak) {
            if (dp[cur][hd][ad][ak] == N) continue;
            if (dp[cur][hd][ad][ak] <= 0) {
              assert(0);
              break;
            }
            if (turn < 10) {
              std::cerr << "# turn # is " << turn << std::endl;
              std::cerr << "# cur # is " << cur << std::endl;
              std::cerr << "# hd # is " << hd << std::endl;
              std::cerr << "# ad # is " << ad << std::endl;
              std::cerr << "# ak # is " << ak << std::endl;
              std::cerr << "# dp[cur][hd][ad][ak] # is " << dp[cur][hd][ad][ak] << std::endl;
            }
            noValid = 0;
            //you turn 
            //1 attack
            {
              int new_hd;
              int new_ad;
              int new_hk = dp[cur][hd][ad][ak] - ad;
              int new_ak = ak;
              if (new_hk <= 0) {
                isFinish = 1;
                ans = turn;
                break;
              } else {
                new_hd = hd - ak;
                new_ad = ad;
                if (new_hd > 0) {
                  toMin(dp[next][new_hd][new_ad][new_ak], new_hk);
                }
              }
            }
            //2 buff
            {
              int new_hd = hd - ak;
              int new_ad = std::min(100, ad + B);
              int new_hk = dp[cur][hd][ad][ak];
              int new_ak = ak;
              if (new_hd > 0) {
                toMin(dp[next][new_hd][new_ad][new_ak], new_hk);
              }
            }
            //3 cure 
            {
              int new_hd = HP - ak;
              int new_ad = ad;
              int new_hk = dp[cur][hd][ad][ak];
              int new_ak = ak;
              if (new_hd > 0) toMin(dp[next][new_hd][new_ad][new_ak], new_hk);
            }
            //4 debuff 
            {
              if (ak <= 0) continue;
              int new_ak = std::max(0, ak - D);
              int new_hk = dp[cur][hd][ad][ak];
              int new_ad = ad;
              int new_hd = hd - new_ak;
              if (new_hd > 0) {
                toMin(dp[next][new_hd][new_ad][new_ak], new_hk);
              }
            }
          }
          if (isFinish) break;
        }
        if (isFinish) break;
      }
      if (isFinish) break;
      if (turn < 10) std::cerr << "# noValid # is " << noValid << std::endl;
      if (noValid) {
        bad = 1;
        break;
      }
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          for (int t = 0; t < N; ++t) {
            dp[cur][j][k][t] = N;
          }
        }
      }
      cur = next;
    }
    if (bad || ans == 0) {
      std::cout << "IMPOSSIBLE" << std::endl;
    } else {
      std::cout << ans << std::endl;
    }
  }

  return 0;
}
