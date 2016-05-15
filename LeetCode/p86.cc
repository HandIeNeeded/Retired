/*************************************************************************
  > File Name: p86.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 14 May 2016 06:42:44 PM CST
 *************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
  public:
    void Append(ListNode *&tail, int x) {
      tail->next = new ListNode(x);
      tail = tail->next;
    }

    ListNode* partition(ListNode* head, int x) {
      ListNode *A = new ListNode(0), *B = new ListNode(0);
      ListNode *tailA = A, *tailB = B;
      while (head != NULL) {
        if (head->val < x) Append(tailA, head->val);
        else Append(tailB, head->val);
        head = head->next;
      }
      tailA->next = B->next;
      return A->next;
    }
};
