//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        if(accumulate(arr, arr + N, 0) & 1) return 0;
        int sum = accumulate(arr, arr + N, 0) / 2;
        // Simple subSet Waala code Use kiya 
        bool dp[N + 1][sum + 1];
        for(int i = 0 ; i < N + 1 ; i++) {
            for(int j = 0 ; j < sum + 1 ; j++) {
                if(i == 0 && j != 0) {
                    dp[i][j] = false;
                }
                else if(j == 0) {
                    dp[i][j] = true;
                }
                else if(arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if(dp[N][sum] == true) return 1;
        return 0;
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends