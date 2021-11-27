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
    ListNode* midnode(ListNode* head){
        if(head==nullptr or head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=nullptr and fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode *head){
        if(head==nullptr or head->next==nullptr) return head;
        
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* forw=nullptr;
        
        while(curr!=nullptr){
            forw = curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return;
        
        ListNode *mid=midnode(head);
        ListNode *newHead=mid->next;
        mid->next=nullptr;
        
        newHead = reverse(newHead);
        
        ListNode* c1=head;
        ListNode* c2=newHead;
        ListNode* f1=nullptr;
        ListNode *f2=nullptr;
        
        while(c2!=nullptr){
            f1=c1->next;
            f2=c2->next;
            
            c1->next=c2;
            c2->next=f1;
            
            c1=f1;
            c2=f2;
        }
    }
};