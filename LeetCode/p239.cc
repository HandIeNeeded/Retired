/*************************************************************************
	> File Name: p239.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Tue 17 May 2016 09:12:05 PM CST
*************************************************************************/
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    vector<int> answer;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (que.size() && que.front() <= i - k) que.pop_front();
      while (que.size() && nums[i] >= nums[que.back()]) {
        que.pop_back();
      }
      que.push_back(i);
      if (i >= k - 1) answer.push_back(nums[que.front()]);
    }
    return answer;
  }
};
