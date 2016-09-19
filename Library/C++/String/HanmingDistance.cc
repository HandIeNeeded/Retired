template<int max_size>
class HanmingDistanceSolver {
public:
  HanmingDistanceSolver(const std::string& a = "", const std::string &b = ""): A(a), B(b) {
    memset(dp, 0, sizeof(dp));
  } 

  int GetDistance() {
    for (int i = 0; i < N; ++i) dp[i][0] = dp[0][i] = i;
    for (int i = 1; i <= (int) A.size(); ++i) {
      for (int j = 1; j <= (int) B.size(); ++j) {
        int &answer = dp[i][j];
        answer = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
        answer = std::min(answer, dp[i - 1][j - 1] + 1);
        if (A[i - 1] == B[j - 1]) answer = std::min(answer, dp[i - 1][j - 1]);
      }
    }
    return dp[A.size()][B.size()];
  }

  static const int N = max_size;

private:
  std::string A, B;
  int dp[N][N];
};
