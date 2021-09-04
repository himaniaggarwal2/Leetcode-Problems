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
    ListNode* midnode(ListNode* head){ //Here we are finding out the middle of the node using Floyds Algo.
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode *head){
        if(head==NULL or head->next==NULL) return head;
        
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forw=NULL;
        
        while(curr!=NULL){
            forw=curr->next; //backup
            curr->next=prev; //link
            
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL) return true;
        
        ListNode *mid=midnode(head);
        ListNode *nHead=mid->next;
        mid->next=NULL;
        
        nHead= reverse(nHead);
        
        ListNode *i = head;
        ListNode *j = nHead;
        
        bool res=true;
        while(j!=NULL){
            if(i->val!=j->val){
                res=false;
                break;
            }
            
            i=i->next;
            j=j->next;
        }
        nHead=reverse(nHead);
        mid->next=nHead;
        
        return res;
    }
};