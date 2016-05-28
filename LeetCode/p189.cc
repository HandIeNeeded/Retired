/*************************************************************************
  > File Name: p189.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Fri 13 May 2016 05:19:14 PM CST
 *************************************************************************/
class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
      k %= nums.size();
      k = nums.size() - k;
      if (k == nums.size()) k = 0;
      reverse(nums.begin(), nums.begin() + k);
      reverse(nums.begin() + k, nums.end());
      reverse(nums.begin(), nums.end());
    }
};

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
      k %= nums.size();
      k = nums.size() - k;
      if (k == nums.size()) k = 0;
      vector<int> tmp = nums;
      for (int i = 0; i < nums.size(); i++) {
        nums[i] = tmp[(i + k) % nums.size()];
      }
    }
};
