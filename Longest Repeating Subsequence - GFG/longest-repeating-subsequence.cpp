//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int dp[str.size() + 1][str.size() + 1];
		    for(int i = 0 ; i < str.size() + 1 ; i++) {
		        for(int j = 0 ; j < str.size() + 1 ; j++) {
		            if(i == 0 || j == 0) {
		                dp[i][j] = 0;
		            }
		            // Agar (i == j) hua toh same index dono string mein aa jaayega 
		            // That's why ye condition lagaana bhut important thaa 
		            else if(str[i - 1] == str[j - 1] && i != j) {
		                dp[i][j] = 1 + dp[i - 1][j - 1];
		            }
		            else {
		                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		            }
		        }
		    }
		    return dp[str.size()][str.size()];
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