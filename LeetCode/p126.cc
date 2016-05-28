/*************************************************************************
  > File Name: p126.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Mon 23 May 2016 10:48:35 PM CST
 *************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> edgeList;
    vector<string> words;
    vector<int> distanceFromStart;
    vector<vector<vector<string>>> memory;
    vector<bool> visited;

    vector<vector<string>> dfs(int nowNode) {
      if (nowNode == 0) {
        vector<string> result;
        vector<vector<string>> answer;
        result.push_back(words[0]);
        answer.push_back(result);
        return answer;
      }
      else if (visited[nowNode]) return memory[nowNode];
      else {
        visited[nowNode] = true;
        vector<vector<string>> &answer = memory[nowNode];
        for (auto &nextNode: edgeList[nowNode]) {
          if (distanceFromStart[nextNode] == distanceFromStart[nowNode] - 1) {
            vector<vector<string>> previousAnswer = dfs(nextNode);
            for (auto result: previousAnswer) {
              result.push_back(words[nowNode]);
              answer.push_back(result);
            }
          }
        }
        return answer;
      }
    }

    bool IsHasEdge(int a, int b) {
      if (words[a].size() != words[b].size()) return 0;
      int diffCount = 0;
      for (int i = 0; i < words[a].size(); i++) {
        diffCount += (words[a][i] != words[b][i]);
      }
      return diffCount == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
      vector<vector<string>> answer;
      if (beginWord == endWord) {
        vector<string> result;
        result.push_back(beginWord);
        answer.push_back(result);
        return answer;
      }
      words.push_back(beginWord), words.push_back(endWord);
      int totalWord = 2;
      for (auto &str: wordList) {
        if (str == beginWord) continue;
        if (str == endWord) continue;
        totalWord++;
        words.push_back(str);
      }
      edgeList.resize(totalWord);
      for (int i = 0; i < totalWord; i++) {
        for (int j = i + 1; j < totalWord; j++) {
          if (IsHasEdge(i, j)) {
            edgeList[i].push_back(j);
            edgeList[j].push_back(i);
          }
        }
      }
      distanceFromStart = vector<int> (totalWord, -1);
      distanceFromStart[0] = 0;
      queue<int> que;
      que.push(0);
      while (que.size()) {
        int nowNode = que.front(); 
        que.pop();
        for (auto &nextNode: edgeList[nowNode]) {
          if (distanceFromStart[nextNode] >= 0) continue;
          else {
            distanceFromStart[nextNode] = distanceFromStart[nowNode] + 1;
            que.push(nextNode);
          }
        }
      }
      if (distanceFromStart[1] < 0) return answer;
      memory.resize(totalWord, vector<vector<string>>());
      visited.resize(totalWord, false);
      vector<vector<string>> anwser = dfs(1);
      //for (auto &result: answer) {
      //  reverse(result.begin(), result.end());
      //}
      return answer;
    }
};

int main() {
  Solution solver;
  unordered_set<string> words;
  words.insert("a"), words.insert("b"), words.insert("c");
  vector<vector<string>> answer = solver.findLadders("a", "c", words);
  return 0;
}
