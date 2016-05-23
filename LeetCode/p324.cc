/*************************************************************************
	> File Name: p324.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 23 May 2016 12:50:49 AM CST
*************************************************************************/
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> answer(nums.size());
		map<int, int> count;
		for (int i = 0; i < nums.size(); i++) count[nums[i]]++;
		int mx = 0, idx = INT_MIN;
		for (auto &p: count) {
      if (p.second > mx) {
        mx = p.second;
        idx = p.first;
      }
    }
		int now = 0;
		int pos = find(nums.begin(), nums.end(), idx) - nums.begin();
		for (int i = pos, j = 0; j < nums.size(); j++, i++, i %= nums.size()) {
			answer[now] = nums[i];
			now += 2;
			if (now >= nums.size()) now = 1;
		}
		nums = answer;
	}
};
