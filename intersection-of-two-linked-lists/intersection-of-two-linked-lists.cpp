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
    ListNode* cycle(ListNode* head1){
       if(head1==nullptr or head1->next==nullptr) return nullptr;
       ListNode* slow=head1,*fast=head1;

       while(fast!=nullptr and fast->next!=nullptr){
           slow=slow->next;
           fast=fast->next->next;

           if(slow==fast) break;
       }

       if(slow!=fast) return nullptr;
       
       slow=head1;
       while(slow!=fast){
           slow=slow->next;
           fast=fast->next;
       }
       return slow;
    }
    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
       if(head1==nullptr or head2==nullptr) return nullptr;
    
        ListNode* tail=head1;
        while(tail->next!=nullptr){
            tail=tail->next;
        }

        tail->next=head2;

        ListNode *ans=cycle(head1);

        tail->next=nullptr;

        return ans;
    }
};