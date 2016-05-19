/*************************************************************************
	> File Name: p329.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 16 May 2016 06:28:59 PM CST
*************************************************************************/
class Solution {
public:
  int n, m;
  int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
  vector<vector<int>> matrix, dp;
  bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int tx = x + dx[i], ty = y + dy[i];
      if (isValid(tx, ty) && matrix[tx][ty] > matrix[x][y]) {
        dfs(tx, ty);
        dp[x][y] = max(dp[x][y], dp[tx][ty] + 1);
      }
    }
    return dp[x][y];
  }

  int longestIncreasingPath(vector<vector<int>>& Matrix) {
    matrix = Matrix;
    n = matrix.size();
    if (n == 0) return 0;
    m = matrix[0].size();
    dp = vector<vector<int>> (n, vector<int>(m, 0));
    int answer = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!dp[i][j]) {
          answer = max(answer, dfs(i, j));
        }
      }
    }
    return answer;
  }
};
