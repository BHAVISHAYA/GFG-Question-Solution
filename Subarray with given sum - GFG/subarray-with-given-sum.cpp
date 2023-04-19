//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> v;
        if(s == 0) {
            v.push_back(-1);
            return v;
        }
        int fast = 0, slow = 0;
        long long sum = arr[0];
        if(sum == s) {
            v.push_back(1);
            v.push_back(1);
            return v;
        }
        while(fast < n - 1) {
            if(sum + arr[fast + 1] <= s) {
                sum += arr[fast + 1];
                fast++;
            }
            else {
                sum -= arr[slow];
                slow++;
            }
            if(sum == s) {
                v.push_back(slow + 1);
                v.push_back(fast + 1);
                return v;
            }
        }
        v.push_back(-1);
        return v;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends