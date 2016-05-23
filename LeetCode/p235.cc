/*************************************************************************
	> File Name: p235.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 10:58:53 PM CST
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || p == NULL || q == NULL) return root;
    while (true) {
      int val = root->val;
      if (p->val < val && q->val < val) {
        root = root->left;
      }
      else if (p->val > val && q->val > val) {
        root = root->right;
      }
      else return root;
    }
  }
};
