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
    ListNode* midNode(ListNode* head){
        if(head==nullptr or head->next==nullptr) return head;
        
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=nullptr and fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeTwoSLL(ListNode* l1, ListNode* l2){
        if(l1==nullptr or l2==nullptr) return l1!=nullptr? l1: l2;
        
        ListNode* c1=l1;
        ListNode* c2=l2;
        ListNode *dummy=new ListNode(-1);
        ListNode* prev=dummy;
        
        while(c1!=nullptr and c2!=nullptr){
            if(c1->val<c2->val){
                prev->next=c1;
                c1=c1->next;
            }else{
                prev->next=c2;
                c2=c2->next;
            }
            prev=prev->next;
        }
        prev->next = c1 != nullptr ? c1 : c2;
        
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        
        ListNode* mid=midNode(head);
        ListNode* nHead=mid->next;
        mid->next=nullptr;
        
        ListNode* l1= sortList(head);
        ListNode* l2= sortList(nHead);
        
        return mergeTwoSLL(l1,l2);
    }
};