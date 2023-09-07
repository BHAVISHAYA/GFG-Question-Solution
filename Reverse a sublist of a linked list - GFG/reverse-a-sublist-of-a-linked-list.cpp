//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insert(Node* &head, int data) {
        Node* newNode = new Node(data);
        if(head == NULL) 
        head = newNode;
        else {
            newNode -> next = head;
            head = newNode;
        }
        return head;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node* temp = head;
        Node* newHead = NULL;
        int ct = 0;
        while(temp != NULL) {
            ct++;
            if(ct >= m && ct <= n) 
            newHead = insert(newHead, temp -> data);
            temp = temp -> next;
        }
        temp = head;
        Node* tmp = newHead;
        ct = 0;
        while(temp != NULL) {
            ct++;
            if(ct >= m && ct <= n) {
                temp -> data = tmp -> data;
                tmp = tmp -> next;
            }
            temp = temp -> next;
        }
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends