//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> ans(2);
        int mn = INT_MAX, slow = 0, fast = m - 1, a = -1, b = -1;
        while(slow < n && fast >= 0) {
            int sum = arr[slow] + brr[fast];
            int diff = abs(sum - x);
            if(diff < mn) {
                mn = diff;
                ans[0] = arr[slow];
                ans[1] = brr[fast];
            }
            if(sum > x)
            fast--;
            else 
            slow++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends