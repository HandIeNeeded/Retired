/*************************************************************************
	> File Name: p53.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 14 May 2016 09:50:36 PM CST
*************************************************************************/
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (nums.size() == 0) return 0;
    int answer = *max_element(nums.begin(), nums.end());
    int now = 0;
    for (int i = 0; i < n; i++) {
      now += nums[i];
      now = max(0, now);
      if (now == 0) continue;
      answer = max(answer, now);
    }
    return answer;
  }
};
