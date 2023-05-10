//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getLength(Node* &head) {
    int ct = 0;
    Node* temp = head;
    while(temp != NULL) {
        ct++;
        temp = temp -> next;
    }
    return ct;
}
int getNthFromLast(Node *head, int n)
{
    // Your code here
    if(n == 0) return -1;
    if(n > getLength(head)) return -1;
    int j = getLength(head) - n + 1;
    int ct = 1;
    if(j == 1) return head -> data;
    Node* temp = head;
    while(temp != NULL && ct < j) {
        temp = temp -> next;
        ct++;
        if(ct == j) return temp -> data;
    }
}

