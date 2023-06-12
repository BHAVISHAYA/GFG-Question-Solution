//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int getMaxProfit(int length[], int price[], int n, int L) {
    	int dp[n + 1][L + 1];
    	for (int i = 0; i <= n; i++)
    		for (int j = 0; j <= L; j++)
    			if (j == 0 || i == 0)
    				dp[i][j] = 0;
    
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= L; j++) {
    			if (length[i - 1] <= j) {
    				dp[i][j] = max(dp[i - 1][j],
    				               price[i - 1] + dp[i][j - length[i - 1]]);
    			}
    			else
    				dp[i][j] = dp[i - 1][j];
    		}
    	}
    
    	return dp[n][L];
    }
    int cutRod(int price[], int n) {
        int len[n];
        for(int i = 0 ; i < n ; i++) {
            len[i] = i + 1;
        }
        return getMaxProfit(len, price, n, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends