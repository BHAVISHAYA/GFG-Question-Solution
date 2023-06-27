//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string S, int n) { 
    //complete the function here 
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