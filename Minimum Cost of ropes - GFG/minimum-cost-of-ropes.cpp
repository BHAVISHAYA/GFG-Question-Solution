//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long int cost = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int >> minHeap;
        for(int i = 0 ; i < n ; i++) {
            minHeap.push(arr[i]);
        }
        while(minHeap.size() >= 2) {
            long long int rope1 = minHeap.top();
            minHeap.pop();
            long long int rope2 = minHeap.top();
            minHeap.pop();
            cost += (rope1 + rope2);
            minHeap.push(rope1 + rope2);
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends