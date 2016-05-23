/*************************************************************************
	> File Name: p83.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 11:38:02 PM CST
*************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* now = head;
    if (now == NULL) return head;
    while (now != NULL && now->next != NULL) {
      while (now->next != NULL && now->val == now->next->val) {
        now->next = now->next->next;
      }
      now = now->next;
    }
    return head;
  }
};

int main() {
  ListNode *root = new ListNode(3), *previous;
  previous = root, root = new ListNode(3), root->next = previous;
  previous = root, root = new ListNode(2), root->next = previous;
  previous = root, root = new ListNode(1), root->next = previous;
  previous = root, root = new ListNode(1), root->next = previous;
  previous = root;
  while (root != NULL) {
    cout << root->val << ' ';
    root = root->next;
  }
  Solution solver;
  solver.deleteDuplicates(previous);
  while (previous != NULL) {
    previous = previous->next;
  }
  return 0;
}
