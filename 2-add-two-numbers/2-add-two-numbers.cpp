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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* forw=nullptr;
        
        while(curr!=nullptr){
            forw = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* c1, ListNode* c2) {
        if(c1==nullptr or c2==nullptr) return c1==nullptr?c2:c1;
        
        // ListNode* c1= reverse(l1);
        // ListNode* c2= reverse(l2);
        
        ListNode* head =  new ListNode(-1);
        ListNode* itr=head;
        
        int carry=0;
        while(c1!=nullptr or c2!=nullptr or carry!=0){
            int sum = carry + (c1 != nullptr ? c1->val: 0) + (c2 != nullptr ? c2->val : 0);
            int ld= sum%10;
            carry = sum/10;
            
            ListNode* temp =  new ListNode (ld);
            itr->next = temp;
            itr = itr->next;
            
            if(c1 != nullptr) c1 = c1->next;
            if(c2 != nullptr) c2 = c2->next;
            
        }
        
        return head->next;
    }
};