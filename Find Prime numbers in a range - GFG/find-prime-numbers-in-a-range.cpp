//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPrime(long long int n) {
        if(n == 1) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        long long int i = 5;
        for(i = 5 ; i * i <= n ; i = i + 6) {
            if(n % i == 0 || n % (i + 2) == 0) 
            return false;
        }
        return true;
    }
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int> v;
        for(int i = M ; i <= N ; i++) {
            if(isPrime(i)) 
            v.push_back(i);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends