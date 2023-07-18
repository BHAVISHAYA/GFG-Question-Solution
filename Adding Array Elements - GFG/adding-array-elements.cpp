//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ctOp = 0;
        for(int i = 0 ; i < n ; i++) {
            minHeap.push(arr[i]);
        }
        while(minHeap.top() < k) {
            int first = minHeap.top();
            minHeap.pop();
            int second;
            if(minHeap.size() > 0) {
                second = minHeap.top();
                minHeap.pop();
            }
            else 
            return -1;
            minHeap.push(first + second);
            ctOp++;
        }
        return ctOp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends