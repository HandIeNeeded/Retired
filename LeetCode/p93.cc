/*************************************************************************
	> File Name: p93.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 14 May 2016 09:39:10 PM CST
*************************************************************************/
//can be optimized to use O(1) space
//only dp[i-1], dp[i-2] are useful
class Solution {
public:
  int numDecodings(string s) {
    if (s.size() == 0) return 0;
    if (s[0] == '0') return 0;
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = 0;
      if (s[i - 1] != '0') dp[i] += dp[i - 1];
      if (s[i - 2] != '0') {
        int x = stoi(s.substr(i - 2, 2));
        if (x >= 1 && x <= 26) dp[i] += dp[i - 2];
      }
    }
    return dp[n];
  }
};
