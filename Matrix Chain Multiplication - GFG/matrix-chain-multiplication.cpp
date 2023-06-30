//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // Method :- 1 Recursive Approach
    // int MCM(int arr[], int i, int j) {
    //     // Base Condition
    //     if(i >= j) return 0;
        
    //     int ans = INT_MAX;
    //     // Move K from i to j - 1;
    //     for(int k = i ; k <= j - 1 ; k++) {
    //         int tempAns = MCM(arr, i, k) + MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            
    //         if(tempAns < ans) 
    //         ans = tempAns;
    //     }
    //     return ans;
    // }
    
    
    // Bottom Up Approach
    int dp[101][101];
    int MCM(int arr[], int i, int j) {
        // Base Condition
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i ; k <= j - 1 ; k++) {
            int tempAns = MCM(arr, i, k) + MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            
            if(tempAns < ans) 
            ans = tempAns;
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return MCM(arr, 1, N - 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends