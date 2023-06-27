//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        string S1 = S;
        reverse(S1.begin(), S1.end());
        int dp[S.size() + 1][S.size() + 1];
        for(int i = 0 ; i < S.size() + 1 ; i++) {
            for(int j = 0 ; j < S.size() + 1 ; j++) {
                if(i == 0 || j == 0) 
                dp[i][j] = 0;
                else if(S[i - 1] == S1[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return (S.size() - dp[S.size()][S.size()]);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends