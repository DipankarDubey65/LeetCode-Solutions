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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
       
        int size =1;
        ListNode* t = head;
        while(t->next != NULL){
            size++;
            t= t->next;
        }
        k = k%size;
        if(k==0){
            return head;
        }
        int tr = size-k-1;
        ListNode* curr = head;
        while(tr--){
            curr = curr->next;
        }
        ListNode* newhead = curr->next;
       
        curr->next = NULL;
        t->next = head;
       return newhead;
    }
};