//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> matrix)
    {
        for(int i = 0 ; i < n ; i++) {
            if(matrix[i][0] == 'O')
            dfs(matrix, i, 0, 'O', '-', n, m);
            if(matrix[i][m - 1] == 'O')
            dfs(matrix, i, m - 1, 'O', '-', n, m);
        }

        for(int i = 0 ; i < m ; i++) {
            if(matrix[0][i] == 'O') 
            dfs(matrix, 0, i, 'O', '-', n, m);
            if(matrix[n - 1][i] == 'O') 
            dfs(matrix, n - 1, i, 'O', '-', n, m);
        }


        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(matrix[i][j] == 'O')
                matrix[i][j] = 'X';

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(matrix[i][j] == '-')
                matrix[i][j] = 'O';

        return matrix;
    }
    void dfs(vector<vector<char>>& matrix, int x, int y, char prevC, char newC, int N, int M) {
        if(x < 0 || x >= N || y < 0 || y >= M)
        return;
        if(matrix[x][y] != prevC)
        return;
        
        matrix[x][y] = newC;
        dfs(matrix, x + 1, y, prevC, newC, N, M);
        dfs(matrix, x - 1, y, prevC, newC, N, M);
        dfs(matrix, x, y + 1, prevC, newC, N, M);
        dfs(matrix, x, y - 1, prevC, newC, N, M);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends