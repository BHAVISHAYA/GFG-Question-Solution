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


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    void insertAtTail(struct Node* &head, struct Node* &tail, int data) {
        if(head == NULL) {
            struct Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else {
            struct Node* newNode = new Node(data);
            tail -> next = newNode;
            tail = newNode;
        }
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code 
        set<int> st;
        struct Node* temp = head1;
        struct Node* tmp = head2;
        struct Node* HEAD = NULL;
        struct Node* TAIL = NULL;
        while(temp != NULL) {
            st.insert(temp -> data);
            temp = temp -> next;
        }
        while(tmp != NULL) {
            st.insert(tmp -> data);
            tmp = tmp -> next;
        }
        for(auto &value : st) {
            insertAtTail(HEAD, TAIL, value);
        }
        return HEAD;
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends