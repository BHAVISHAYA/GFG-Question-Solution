//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
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
/* Node structure

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
    void insert(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void rearrangeEvenOdd(Node *head)
    {
    // Your Code here
        Node* Head = NULL;
        Node* Tail = NULL;
        int ct = 1;
        Node* temp = head;
        while(temp != NULL) {
            if(ct % 2 != 0)
            insert(Head, Tail, temp -> data);
            ct++;
            temp = temp -> next;
        }
        temp = head;
        ct = 1;
        while(temp != NULL) {
            if(ct % 2 == 0) 
            insert(Head, Tail, temp -> data);
            ct++;
            temp = temp -> next;
        }
        temp = head;
        while(Head != NULL) {
            temp -> data = Head -> data;
            temp = temp -> next;
            Head = Head -> next;
        }
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends