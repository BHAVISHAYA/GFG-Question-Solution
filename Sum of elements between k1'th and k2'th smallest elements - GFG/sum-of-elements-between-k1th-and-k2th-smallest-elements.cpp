//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int KthSmallest(long long a[], long long n, long long k) {
        priority_queue<long long> maxHeap;
        for(int i = 0 ; i < n ; i++) {
            maxHeap.push(a[i]);
            if(maxHeap.size() > k)
            maxHeap.pop();
        }
        if(maxHeap.size() > 0)
        return maxHeap.top();
        return -1;
    }
    long long sumBetweenTwoKth( long long A[], long long N,
    long long K1, long long K2)
    {
        // Your code goes 
        int first = KthSmallest(A, N, K1);
        int second = KthSmallest(A, N, K2);
        long long int sum = 0;
        for(int i = 0 ; i < N ; i++) {
            if(A[i] > first && A[i] < second)
            sum += A[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends