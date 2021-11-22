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
    int size(ListNode *root){
        int count=1;
        while(root->next!=NULL){
            root=root->next;
            count++;
        }
        // cout<<count<<endl;
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA;
        ListNode *t2=headB;
        
        int sizeA= size(headA);
        int sizeB = size(headB);
        
        int diff= abs(sizeA-sizeB);
        
        if(sizeA>sizeB){
            for(int i=0;i<diff;i++){
                t1=t1->next;
            }
        }
        else{
            for(int i=0;i<diff;i++){
                t2=t2->next;
            }
        }
        
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
        }
        
        return t1;
    }
};