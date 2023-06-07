//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // bool isPrime(int n) {
    //     if(n == 1) return false;
    //     if(n == 2 || n == 3) return true;
    //     if(n % 2 == 0 || n % 3 == 0) return false;
    //     for(int i = 5 ; i * i <= n ; i = i + 6) {
    //         if(n % i == 0 || (n % (i + 2)) == 0) return false;
    //     }
    //     return true;
    // }
    
    void preCompute(int n, vector<int> &v) {
        vector<bool> isPrime(n + 1, true);
        for(int i = 2 ; i <= n ; i++) {
            if(isPrime[i]) {
                v.push_back(i);
                for(int j = i * i ; j <= n ; j = j + i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> prime;
        preCompute(n, prime);
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        for(int i = 2 ; i <= n ; i++) {
            for(int j = 0 ; j < prime.size() ; j++) {
                if(i % prime[j] == 0) {
                    ans.push_back(prime[j]);
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends