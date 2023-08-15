//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    int getLength(struct Node* &head) {
        int ct = 0;
        struct Node* temp = head;
        while(temp != NULL) {
            ct++;
            temp = temp -> next;
        }
        return ct;
    }
    void insert(struct Node* &head, int data) {
        struct Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
        }
        else {
            newNode -> next = head;
            head = newNode;
        }
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node* head = NULL;
        int lenList1 = getLength(first);
        int lenList2 = getLength(second);
        vector<int> list1, list2;
        list1.push_back(0);
        list2.push_back(0);
        if(lenList1 < lenList2) {
            int extra = lenList2 - lenList1;
            while(extra--) {
                list1.push_back(0);
            }
        }
        else if(lenList2 < lenList1) {
            int extra = lenList1 - lenList2;
            while(extra--) {
                list2.push_back(0);
            }
        }
        struct Node* temp = first;
        while(temp != NULL) {
            list1.push_back(temp -> data);
            temp = temp -> next;
        }
        temp = second;
        while(temp != NULL) {
            list2.push_back(temp -> data);
            temp = temp -> next;
        }
        int sum = list1[list1.size() - 1] + list2[list2.size() - 1];
        for(int i = list1.size() - 1 ; i > 0 ; i--) {
            if(sum <= 9) {
                list1[i] = sum;
                list1[i - 1] = list1[i - 1] + list2[i - 1];
                sum = list1[i - 1];
            }
            else {
                list1[i] = sum % 10;
                sum = sum / 10;
                list1[i - 1] = list1[i - 1] + list2[i - 1] + sum;
                sum = list1[i - 1];
            }
        }
        if(list1[0] == 0) 
        list1.erase(list1.begin() + 0);
        for(int i = list1.size() - 1 ; i >= 0 ; i--) {
            insert(head, list1[i]);
        }
        return head;
    }
};


//{ Driver Code Starts.

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
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends