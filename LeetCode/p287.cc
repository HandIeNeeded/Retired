/*************************************************************************
  > File Name: p287.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Thu 12 May 2016 08:00:09 PM CST
 *************************************************************************/
class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        int answerL = 0, answerR = 0;
        for (int j = i + 1; j < n; j++) {
          answerL ^= nums[j];
          if (j > i + 1) answerR ^= nums[j - 1];
          if (answerL == answerR) return nums[j];
        }
      }
      return -1;
    }
};

class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      int lo = 0, hi = n - 1;
      while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        int count = 0;
        for (auto &x: nums) {
          if (x <= mid) count++;
        }
        if (count > mid) hi = mid;
        else lo = mid;
      }
      return hi;
    }
};
