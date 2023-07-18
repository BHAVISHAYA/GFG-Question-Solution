//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int LCS(string &x, string &y) {
	        int dp[x.size() + 1][x.size() + 1];
	        for(int i = 0 ; i < x.size() + 1 ; i++) {
	            for(int j = 0 ; j < x.size() + 1 ; j++) {
	                if(i == 0 || j == 0) {
	                    dp[i][j] = 0;
	                }
	                else if(x[i - 1] == y[j - 1] && i != j) {
	                    dp[i][j] = 1 + dp[i - 1][j - 1];
	                }
	                else {
	                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	                }
	            }
	        }
	        return dp[x.size()][x.size()];
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    return LCS(str, str);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends