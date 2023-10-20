//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int digitSum(int n) {
        long long int ans = 0;
        while(n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int isPossible(int N, int arr[]) {
        // code here
        long long int sum = 0;
        for(int i = 0 ; i < N ; i++) {
            sum += digitSum(arr[i]);
        }
        if(sum % 3 == 0) return 1;
        return 0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends