//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    vector<long long> ne;
    long long int slow = 0, fast = 0;
    while(fast < N) {
        if(A[fast] < 0) {
            ne.push_back(A[fast]);
        }
        if(fast - slow + 1 < K)
        fast++;
        else if(fast - slow + 1 == K) {
            if(ne.size() == 0) 
            ans.push_back(0);
            else 
            ans.push_back(ne.front());
            if(ne.size() > 0 && ne.front() == A[slow]) 
            ne.erase(ne.begin() + 0);
            slow++;
            fast++;
        }
    }
    return ans;
}