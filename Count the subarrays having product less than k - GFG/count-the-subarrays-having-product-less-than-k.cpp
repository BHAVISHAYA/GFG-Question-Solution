//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int product = 1;
        int ans = 0, slow = 0, fast = 0;
        for(slow < 0, fast < 0 ; fast < n ; fast++) {
            product = product * a[fast];
            while(product >= k && slow < fast) {
                product = product / a[slow];
                slow++;
            }
            if(product < k) 
            ans += (fast - slow + 1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends