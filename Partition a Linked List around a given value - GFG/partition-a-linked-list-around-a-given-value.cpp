//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

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
struct Node* reverse(struct Node* &head) {
    struct Node* forward = NULL;
    struct Node* prev = NULL;
    struct Node* curr = head;
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}
struct Node* partition(struct Node* head, int x) {
    // code here
    struct Node* h = NULL;
    struct Node* l = NULL;
    struct Node* e = NULL;
    struct Node* t = head;
    while(t != NULL) {
        if(t -> data < x) 
        insert(l, t -> data);
        else if(t -> data == x) 
        insert(e, t -> data);
        else 
        insert(h, t -> data);
        t = t -> next;
    }
    l = reverse(l);
    e = reverse(e);
    h = reverse(h);
    t = head;
    while(l != NULL) {
        t -> data = l -> data;
        t = t -> next;
        l = l -> next;
    }
    while(e != NULL) {
        t -> data = e -> data;
        t = t -> next;
        e = e -> next;
    }
    while(h != NULL) {
        t -> data = h -> data;
        t = t -> next;
        h = h -> next;
    }
    return head;
}