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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL){
			return l2;
		}
		if(l2 == NULL){
			return l1;
		}        
		if(l1->val < l2->val){
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;            
		}
	}
    
    ListNode* mergeKLists(vector<ListNode*>& lists,int si, int ei) {
        if(si>ei) return nullptr;
        if(si == ei) return lists[si];
        int mid=(si+ei)/2;
        
        ListNode *l1=mergeKLists(lists,si,mid);
        ListNode *l2=mergeKLists(lists,mid+1,ei);
        
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return mergeKLists(lists,0,lists.size()-1);
    }
};