/*************************************************************************
	> File Name: p226.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 01:44:19 AM CST
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
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  void print(TreeNode* root) {
    if (root == NULL) return ;
    cout << root->val << endl;
    print(root->left), print(root->right);
  }

  void dfs(TreeNode* &root) {
    if (root == NULL) return ;
    dfs(root->left), dfs(root->right);
    cout << root << ' ' << root->left << ' ' << root->right << endl;
    swap(root->left, root->right);
    cout << root << ' ' << root->left << ' ' << root->right << endl;
  }

  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return root;
    dfs(root);
    return root;
  }
};

int main() {
  Solution solver;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  solver.print(root);
  solver.invertTree(root);
  solver.print(root);
  return 0;
}
