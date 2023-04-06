//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        printList(makeUnion(first,second));
    }
    return 0;
}

// } Driver Code Ends


/*
// structure of the node is as follows

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

void insertAtTail(struct Node* &tail, struct Node* &head, int data) {
    if(tail == NULL) {
        struct Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else {
        struct Node* newNode = new Node(data);
        tail -> next = newNode;
        tail = newNode;
    }
}

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    // code here
    struct Node* tail = NULL;
    struct Node* head = NULL;
    set<int> st;
    while(head1 != NULL) {
        st.insert(head1 -> data);
        head1 = head1 -> next;
    }
    while(head2 != NULL) {
        st.insert(head2 -> data);
        head2 = head2 -> next;
    }
    for(auto &value : st) {
        insertAtTail(tail, head, value);
    }
    return head;
}
