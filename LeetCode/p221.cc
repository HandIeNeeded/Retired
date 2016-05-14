/*************************************************************************
	> File Name: 221.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 12 May 2016 05:21:58 PM CST
*************************************************************************/
class Solution {
public:
  int maximalSquare(vector<vector<char> > &matrix) {
    if (matrix.size() == 0) return 0;
    int n, m;
    n = matrix.size(), m = matrix[0].size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1] - '0';
      }
    }
    int lo = 0, hi = min(n, m) + 1;
    while (lo + 1 < hi) {
      int middle = (lo + hi) / 2;
      int good = 0;
      for (int i = middle; i <= n; i++) {
        for (int j = middle; j <= m; j++) {
          int x = i - middle, y = j - middle;
          if (dp[i][j] - dp[x][j] - dp[i][y] + dp[x][y] == middle * middle) {
            good = 1;
            break;
          }
        }
        if (good) break;
      }
      if (good) {
        lo = middle;
      }
      else {
        hi = middle;
      }
    }
    return lo * lo;
  }
};
