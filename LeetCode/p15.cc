/*************************************************************************
  >         File: p15.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 18 Aug 2016 12:01:52 AM CST
 *************************************************************************/
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      unordered_set<int> s;
      std::vector<std::vector<int>> ans;
      for (int bound = n - 1; bound > 1; bound--) {
        s.insert(nums[bound]);
        for (int ia = 0; ia < bound; ia++) {
          for (int ib = ia + 1; ib < bound; ib++) {
            int sum = -(nums[ia] + nums[ib]);
            if (s.count(sum) > 0) {
              std::vector<int> tmp;
              tmp.push_back(nums[ia]); tmp.push_back(nums[ib]);
              tmp.push_back(sum);
              sort(tmp.begin(), tmp.end());
              ans.push_back(tmp);
            }
          }
        }
      }
      std::sort(ans.begin(), ans.end());
      ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
      return ans;
    }
};
