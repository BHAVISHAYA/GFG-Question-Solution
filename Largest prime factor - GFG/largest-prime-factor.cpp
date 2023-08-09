//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        long long int ans = 0, i;
        for(i = 2 ; i <= N ; i++) {
            while(N % i == 0) {
                if(i > ans) {
                    ans = i;
                }
                N = N / i;
            }
        }
        if(N > 1) {
            if(N > ans) {
                ans = N;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends