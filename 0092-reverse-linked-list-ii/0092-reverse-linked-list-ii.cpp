/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode*  before = NULL;
      int pos = 1;
      ListNode* t = head;
      
      while(pos<left){
        before = t;
        t = t->next;
        pos++;
      }
      ListNode* curr = t;
      ListNode* prev = NULL;
      int times = right-left+1;
      while(times--){
        ListNode* ne = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ne;
      }
      if (before == NULL) {
            head = prev;
        } else {
            before->next = prev;
        }
      t->next =curr;

      return head; 

    }
};