//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        vector<vector<int>> v;
        vector<vector<int>> ans;
        for(int i = 0 ; i < row ; i++) {
            vector<int> t;
            for(int j = 0 ; j < col ; j++) {
                t.push_back(M[i][j]);
            }
            ans.push_back(t);
        }
        set<vector<int>> st;
        for(int i = 0 ; i < ans.size() ; i++) {
            st.insert(ans[i]);
        }
        for(int i = 0 ; i < ans.size() ; i++) {
            if(st.find(ans[i]) != st.end()) {
                v.push_back(ans[i]);
                st.erase(ans[i]);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends