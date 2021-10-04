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
    ListNode* removeNthFromEnd(ListNode* headi, int n) {
        int size=0;
        ListNode *copy=headi;
    
        while(copy!=NULL){
            size++;
            copy=copy->next;
        }
        if(size==1 and n==1){
            headi=headi->next;
            return headi;
        }
        n=size-n;
        if(n==0){
            headi=headi->next;
            return headi;
        }
        size=1;
        ListNode *head=headi;
        while(head!=NULL){
            if(size==n){
                head->next=head->next->next;
            }
            size++;
            head=head->next;
        }
        return headi;
    }
};