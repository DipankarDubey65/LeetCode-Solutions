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
    void reverse_func(ListNode* head,int k){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(k--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;

    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return head;
        }
        int k =2;
        ListNode* left = head;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;
        ListNode* right;
        while(true){
            right = left;
            for(int i=0;i<(k-1);i++){
                if(right==NULL){
                    break;
                }
                right = right->next;
            }
            if(right){
                ListNode* nextleft = right->next;
                reverse_func(left,k);
                if(prevleft){
                    prevleft->next = right;
                }
                prevleft = left;
                if(res==NULL){
                    res = right;
                }
                left =nextleft;
            }
            else{
                if(prevleft){
                    prevleft->next = left; 
                }
                if(res==NULL){
                    res=left;
                }
                break;
            }
        }
        return res;
    }
};