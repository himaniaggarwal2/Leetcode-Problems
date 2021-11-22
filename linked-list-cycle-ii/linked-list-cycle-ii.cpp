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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr or head->next==nullptr) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        // bool isCycle = false;
        
        while(fast!=nullptr and fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){ 
                // isCycle=true;
                break;
            }
        }
        
        if(slow!=fast) return nullptr;
        
        slow=head;
        fast=fast;
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
    }
};