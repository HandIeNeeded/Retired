/*************************************************************************
  >         File: p19.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Wed 17 Aug 2016 11:45:10 PM CST
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head->next == NULL) return NULL;
      ListNode *previous = NULL, *ptrHead = head, *ptrTail = head;
      for (int i = 0; i < n - 1; i++) ptrHead = ptrHead->next;
      while (ptrHead->next != NULL) {
        previous = ptrTail;
        ptrTail = ptrTail->next;
        ptrHead = ptrHead->next;
      }
      if (previous == NULL) return head->next;
      previous->next = ptrTail->next;
      return head;
    }
};
