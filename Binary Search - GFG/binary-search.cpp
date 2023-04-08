//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int lo = 0, hi = n - 1, mid;
        while(hi - lo > 1) {
            mid = (hi + lo) / 2;
            if(arr[mid] < k) 
            lo = mid + 1;
            else 
            hi = mid;
        }
        if(arr[lo] == k) 
        return lo;
        if(arr[hi] == k) 
        return hi;
        return -1;
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
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends