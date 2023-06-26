//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string x, string y) 
	{ 
	    int dp[x.size() + 1][y.size() + 1];
	    for(int i = 0 ; i < x.size() + 1 ; i++) {
	        for(int j = 0 ; j < y.size() + 1 ; j++) {
	            if(i == 0 || j == 0) 
	            dp[i][j] = 0;
	            else if(x[i - 1] == y[j - 1]) 
	            dp[i][j] = 1 + dp[i - 1][j - 1];
	            else 
	            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	        }
	    }
	    int deletion = x.size() - dp[x.size()][y.size()];
	    int insertion = y.size() - dp[x.size()][y.size()];
	    return (deletion + insertion);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends