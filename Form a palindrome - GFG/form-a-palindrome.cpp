//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str) {
        string s = str;
        reverse(s.begin(), s.end());
        int dp[str.size() + 1][s.size() + 1];
        for(int i = 0 ; i < str.size() + 1 ; i++) {
            for(int j = 0 ; j < s.size() + 1 ; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if(str[i - 1] == s[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return (str.size() - dp[str.size()][s.size()]);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends