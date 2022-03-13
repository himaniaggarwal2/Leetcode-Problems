// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    if(head1==nullptr or head2==nullptr) return nullptr;
    Node* l1=head1;
    Node* l2=head2;
    Node* head = new Node (-1);
    Node* dummy = head;
    while(l1!=nullptr and l2!=nullptr){
        if(l1->data==l2->data){
            Node* temp= new Node(l1->data);
            dummy->next=temp;
            dummy=dummy->next;
            l1=l1->next;
            l2=l2->next;
        }else if(l1!=nullptr and l1->data<l2->data){
            l1=l1->next;
        }else if(l2!=nullptr and l2->data<l1->data){
            l2=l2->next;
        }
    }
    return head->next;
}
