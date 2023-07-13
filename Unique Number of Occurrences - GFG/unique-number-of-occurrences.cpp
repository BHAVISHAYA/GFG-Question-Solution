//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        vector<int> v;
        unordered_map<int, int> m;
        for(int i = 0 ; i < n ; i++) {
            m[arr[i]]++;
        }
        for(auto &value : m) {
            v.push_back(value.second);
        }
        if(v.size() == 0 || v.size() == 1) return true;
        sort(v.begin(), v.end());
        for(int i = 0 ; i < v.size() - 1 ; i++) {
            if(v[i] == v[i + 1]) return false;
        }
        return true;
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
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends