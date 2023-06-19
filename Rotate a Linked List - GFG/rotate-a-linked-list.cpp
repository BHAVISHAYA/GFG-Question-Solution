//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list
    void insertAtTail(Node* &head, Node* &tail, int data) {
        if(head == NULL) {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else {
            Node* newNode = new Node(data);
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* temp = head;
        Node* head1 = NULL;
        Node* tail1 = NULL;
        Node* head2 = NULL;
        Node* tail2 = NULL;
        while(temp != NULL) {
            if(k != 0) {
                insertAtTail(head1, tail1, temp -> data);
                k--;
            }
            else {
                insertAtTail(head2, tail2, temp -> data);
            }
            temp = temp -> next;
        }
        Node* tmp = head1;
        while(tmp != NULL) {
            insertAtTail(head2, tail2, tmp -> data);
            tmp = tmp -> next;
        }
        return head2;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
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
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends