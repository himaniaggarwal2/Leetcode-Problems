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
     ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* h = new ListNode(INT_MIN);
        
        while(head!=NULL)
        {
            ListNode* n1 = head->next,*p=h,*n2;
            head->next = NULL;
            while(p->next!=NULL && p->next->val < head->val) p = p->next;
            n2 = p->next;
            p->next = head;
            head->next = n2;
            head = n1;
        }
        
        return h->next;
    };
};