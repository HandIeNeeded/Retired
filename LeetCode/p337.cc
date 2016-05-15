/*************************************************************************
	> File Name: p337.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 15 May 2016 12:56:20 PM CST
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
  pair<int, int> dfs(TreeNode* root) {
    if (root == NULL) return {0, 0};
    int x = 0, y = 0;
    int a = 0, b = 0, c = 0, d = 0;
    if (root->left != NULL) tie(a, b) = dfs(root->left);
    if (root->right != NULL) tie(c, d) = dfs(root->right);
    x = max(a, b) + max(c, d);
    y = a + c + root->val;
    return {x, y};
  }

  int rob(TreeNode* root) {
    int x, y;
    tie(x, y) = dfs(root);
    return max(x, y);
  }
};
