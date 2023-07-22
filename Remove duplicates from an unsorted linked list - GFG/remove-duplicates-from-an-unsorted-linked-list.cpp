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

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

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
        //Function to remove duplicates from unsorted linked list.
        Node* insert(Node* &head, Node* &tail ,int data) {
            Node* newNode = new Node(data);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail -> next = newNode;
                tail = newNode;
            }
            return head;
        }
        Node* removeDuplicates(Node *head) {
            unordered_set<int> st;
            unordered_map<int ,bool> vis;
            Node* temp = head;
            while(temp != NULL) {
                st.insert(temp -> data);
                temp = temp -> next;
            }
            for(auto &value : st) {
                vis[value] = false;
            }
            temp = head;
            Node* Head = NULL;
            Node* Tail = NULL;
            while(temp != NULL) {
                if(vis[temp -> data] == false) {
                    insert(Head, Tail, temp -> data);
                    vis[temp -> data] = true;
                }
                temp = temp -> next;
            }
            return Head;
        }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends