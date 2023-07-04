//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int preIndex = 0;
    Node* Tree(int in[], int pre[], int startIndex, int endIndex) {
        if(startIndex > endIndex) return NULL;
        
        Node* root = new Node(pre[preIndex++]);
        
        int inIndex;
        for(int i = startIndex ; i <= endIndex ; i++) {
            if(in[i] == root -> data) {
                inIndex = i;
                break;
            }
        }
        root -> left = Tree(in, pre, startIndex, inIndex - 1);
        root -> right = Tree(in, pre, inIndex + 1, endIndex);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return Tree(in, pre, 0, n - 1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends