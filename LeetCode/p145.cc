/*************************************************************************
	> File Name: p145.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Fri 20 May 2016 12:28:56 AM CST
*************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void dfs(TreeNode* root, vector<int> &answer) {
    if (root == NULL) return ;
    dfs(root->left, answer);
    dfs(root->right, answer);
    answer.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> answer;
    //dfs(root, answer);
    stack<TreeNode*> stk;
    TreeNode *nowNode = root, *lastNode = NULL;
    while (stk.size() || nowNode != NULL) {
      if (nowNode != NULL) {
        stk.push_back(nowNode);
      }
      else {
        answer.push_back(std.pop()->val);
      }
      if (nowNode->left != NULL) {
        nowNode = nowNode->left;
        answer.push_back(nowNode->val);
      }
      else {
        lastNode = nowNode;
      }
    }
    return answer;
  }
};
