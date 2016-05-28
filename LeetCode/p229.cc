/*************************************************************************
  > File Name: p229.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 21 May 2016 11:41:34 PM CST
 *************************************************************************/
class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      vector<int> answer;
      if (nums.size() == 0) return answer;
      for (int i = 0; i < 2; i++) {
        int x = nums[(i + 1) * n / 3];
        int cnt = 0;
        for (auto&y: nums) if (y == x) cnt++;
        if (cnt > n / 3) answer.push_back(x);
      }
      if (answer.size() > 1) {
        if (answer[0] == answer[1]) answer.pop_back();
      }
      return answer;
    }
};
