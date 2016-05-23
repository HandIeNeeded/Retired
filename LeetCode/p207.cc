/*************************************************************************
	> File Name: p207.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 11:16:01 PM CST
*************************************************************************/
class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> inEdgeCount(numCourses, 0);
    vector<vector<int>> edgeList(numCourses);
    for (auto &p: prerequisites) {
      int x, y;
      tie(x, y) = p;
      edgeList[y].push_back(x);
      inEdgeCount[x]++;
    }
    queue<int> que;
    int courseSettledCount = 0;
    for (int course = 0; course < numCourses; course++) if (inEdgeCount[course] == 0) {
      que.push(course);
    }
    while (que.size()) {
      int course = que.front(); que.pop();
      courseSettledCount++;
      for (auto &nextCourse: edgeList[course]) {
        inEdgeCount[nextCourse]--;
        if (inEdgeCount[nextCourse] == 0) {
          que.push(nextCourse);
        }
      }
    }
    return courseSettledCount == numCourses;
  }
};
