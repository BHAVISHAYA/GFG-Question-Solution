//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> ans;
        unordered_map<int, int> m1, m2;
        for(int i = 0 ; i < n ; i++) {
            if(m1.find(arr[i]) == m1.end()) {
                m1[arr[i]] = i;
            }
            if(m2.find(arr[n - i - 1]) == m2.end()) {
                m2[arr[n - i - 1]] = n - i - 1;
            }
        }
        if(m1.find(x) == m1.end()) return {-1, -1};
        ans.push_back(m1[x]);
        ans.push_back(m2[x]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends