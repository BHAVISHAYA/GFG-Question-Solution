//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string S){
        // code here 
        string s = S;
        reverse(s.begin(), s.end());
        int dp[S.size() + 1][s.size() + 1];
        for(int i = 0 ; i < S.size() + 1 ; i++) {
            for(int j = 0 ; j < s.size() + 1 ; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if(S[i - 1] == s[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return (S.size() - dp[S.size()][s.size()]);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends