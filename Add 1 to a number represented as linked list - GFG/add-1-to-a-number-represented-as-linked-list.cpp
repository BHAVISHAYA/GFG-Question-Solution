//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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
    void insert(Node* &head, int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
        }
        else {
            newNode -> next = head;
            head = newNode;
        }
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* Head = NULL;
        vector<int> list, list2;
        list.push_back(0);
        list2.push_back(0);
        Node* temp = head;
        while(temp != NULL) {
            list.push_back(temp -> data);
            list2.push_back(0);
            temp = temp -> next;
        }
        list2.pop_back();
        list2.push_back(1);
        int sum = list[list.size() - 1] + list2[list2.size() - 1];
        for(int i = list.size() - 1 ; i > 0 ; i--) {
            if(sum <= 9) {
                list[i] = sum;
                list[i - 1] = list[i - 1] + list2[i - 1];
                sum = list[i - 1];
            }
            else {
                list[i] = sum % 10;
                sum = sum / 10;
                list[i - 1] = list[i - 1] + list2[i - 1] + sum;
                sum = list[i - 1];
            }
        }
        if(list[0] == 0)
        list.erase(list.begin() + 0);
        for(int i = list.size() - 1 ; i >= 0 ; i--) {
            insert(Head, list[i]);
        }
        return Head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends