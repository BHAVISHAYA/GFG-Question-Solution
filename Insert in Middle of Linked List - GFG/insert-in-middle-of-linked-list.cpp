//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

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

//Function to insert a node in the middle of the linked list.
int getLength(Node* &head) {
    int ct = 0;
    Node* temp = head;
    while(temp != NULL) {
        ct++;
        temp = temp -> next;
    }
    return ct;
}
void insertAtAnyPosition(Node* &head, int data, int position) {
    if(position == 1) {
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }
    else {
        Node* prev = NULL;
        Node* curr = head;
        int ct = 0;
        while(curr != NULL && ct < position - 1) {
            prev = curr;
            curr = curr -> next;
            ct++;
        }
        Node* newNode = new Node(data);
        newNode -> next = prev -> next;
        prev -> next = newNode;
    }
}
Node* insertInMiddle(Node* head, int x)
{
	// Code here
	if(getLength(head) % 2 == 0)
	insertAtAnyPosition(head, x, (getLength(head) / 2 + 1));
	else 
	insertAtAnyPosition(head, x, (getLength(head) / 2 + 2));
	return head;
}