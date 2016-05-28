/*************************************************************************
  > File Name: p52.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Tue 17 May 2016 09:21:58 PM CST
 *************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:

    int answer, n;

    void go(int dep, int left, int right, int row) {
      //cout << dep << ' ' << left << ' ' << right << ' ' << row << endl;
      if (dep == n) answer++;
      else {
        int limit = (1 << n) - 1;
        int ban = (left << 1 & limit) | (right >> 1) | row;
        int valid = limit ^ ban;
        while (valid) {
          int lowbit = valid & (-valid);
          go(dep + 1, left << 1 & limit | lowbit, right >> 1 | lowbit, row | lowbit);
          valid ^= lowbit;
        }
      }
    }

    int totalNQueens(int N) {
      n = N, answer = 0;
      go(0, 0, 0, 0);
      return answer;
    }
};

int main() {
  Solution queen;
  cout << queen.totalNQueens(4) << endl;
  return 0;
}
