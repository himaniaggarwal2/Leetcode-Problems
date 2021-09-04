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
    ListNode* middleNode(ListNode* head) {
        ListNode* node1=head;
        ListNode* node2=head;
        
        while(node1!=NULL and node1->next!=NULL){ 
            node1=node1->next->next;
            node2=node2->next;
        }
        return node2;
    }
};