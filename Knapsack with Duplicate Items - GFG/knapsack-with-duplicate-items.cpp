//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int KNAPSACK(int wt[], int val[], int W, int N) {
        int dp[W + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= W; i++) {
            for (int j = 1; j <= N; j++) {
                if (i >= wt[j - 1])
                    dp[i] = max(dp[i], dp[i - wt[j - 1]] + val[j - 1]);
            }
        }
        return dp[W];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        return KNAPSACK(wt, val, W, N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends