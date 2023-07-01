//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    
    bool isPalindrome(string &x, int i, int j) {
        if(i >= j) return true;
        if(x[i] != x[j]) return false;
        return isPalindrome(x, i + 1, j - 1);
    }
    
    int PalinPartitioning(string &str, int i, int j) {
        if(i >= j) return 0;
        if(isPalindrome(str, i, j)) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX, left, right;
        
        for(int k = i ; k <= j - 1 ; k++) {
            // Check For Left Part
            if(dp[i][k] != -1) {
                left = dp[i][k];
            }
            else {
                left = PalinPartitioning(str, i, k);
                dp[i][k] = left;
            }
            
            // Check For Right Part
            if(dp[k + 1][j] != -1) {
                right = dp[k + 1][j];
            }
            else {
                right = PalinPartitioning(str, k + 1, j);
                dp[k + 1][j] = right;
            }
            
            
            int tempAns = 1 + left + right;
            
            ans = min(tempAns, ans);
        }
        return ans;
    }
    
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return PalinPartitioning(str, 0, str.size() - 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends