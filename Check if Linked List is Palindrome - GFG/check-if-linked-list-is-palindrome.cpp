//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseTheList(Node* &head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        
        Node* forward = NULL;
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
        return head;
    }
    
    void insertAtTail(Node* &tail, Node* &head, int data) {
        if(head == NULL) {
            Node* newNode = new Node(data);
            tail = newNode;
            head = newNode;
        }
        else {
            Node* newNode = new Node(data);
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head -> next == NULL) return true;
        Node* tail = NULL;
        Node* passToRev = head;
        Node* temp = head;
        Node* hed = NULL;
        while(temp != NULL) {
            insertAtTail(tail, hed,  temp -> data);
            temp = temp -> next;
        }
        Node* mainHead = reverseTheList(passToRev);
        while(mainHead != NULL) {
            if(mainHead -> data != hed -> data) return false;
            mainHead = mainHead -> next;
            hed = hed -> next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends