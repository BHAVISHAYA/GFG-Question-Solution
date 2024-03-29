//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> v(n);
        int need = 0;
        
        for(int i = 0; i < n; i++){
            int row, col;
            row = col = 0;
            
            for(int j = 0; j < n; j++){
                row += matrix[j][i];
                col += matrix[i][j];
            }
            
            need = max({need, row, col});
            v[i] = row;
        }
        
        int ans = 0;
        for(auto i : v)
            ans += need - i;
        return ans;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends