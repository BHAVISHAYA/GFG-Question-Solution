//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1001][1001];
    int LCS(string &x, string &y, int m, int n) {
        // Base Condition
        if(n == 0 || m == 0) return 0;
        
        // Check for values present in matric or not
        if(dp[m][n] != -1) return dp[m][n];
        
        // Choice Diagram Code
        if(x[m - 1] == y[n - 1]) {
            return dp[m][n] = 1 + LCS(x, y, m - 1, n - 1);
        }
        else {
            // We have two choices 
            return dp[m][n] = max(LCS(x, y, m - 1, n), LCS(x, y, m, n - 1));
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return LCS(s1, s2, x, y);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends