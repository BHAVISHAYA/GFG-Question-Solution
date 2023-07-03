//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int v[], int n) {
        vector<int> lmin(n, 0), rmax(n, 0);

        lmin[0] = v[0];
        for(int i = 1 ; i < n ; i++) {
            lmin[i] = min(v[i], lmin[i - 1]);
        }

        rmax[n - 1] = v[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--) {
            rmax[i] = max(rmax[i + 1], v[i]);
        }
        int i = 0, j = 0, maxDiff = 0;
        while(i < n && j < n) {
            if(rmax[j] >= lmin[i]) {
                maxDiff = max(maxDiff, j - i);
                j++;
            }
            else
            i++;
        }
        return maxDiff;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends