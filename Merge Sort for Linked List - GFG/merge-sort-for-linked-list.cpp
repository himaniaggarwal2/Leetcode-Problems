// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* midNode(Node* head){
        if(head==nullptr or head->next==nullptr) return head;
        
        Node *slow=head;
        Node *fast=head;
        while(fast->next!=nullptr and fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* mergeTwoSLL(Node* l1, Node* l2){
        if(l1==nullptr or l2==nullptr) return l1!=nullptr? l1: l2;
        
        Node* c1=l1;
        Node* c2=l2;
        Node *dummy=new Node(-1);
        Node* prev=dummy;
        
        while(c1!=nullptr and c2!=nullptr){
            if(c1->data<c2->data){
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
    
    Node* mergeSort(Node* head) {
        if(head==nullptr or head->next==nullptr) return head;
        
        Node* mid=midNode(head);
        Node* nHead=mid->next;
        mid->next=nullptr;
        
        Node* l1= mergeSort(head);
        Node* l2= mergeSort(nHead);
        
        return mergeTwoSLL(l1,l2);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends