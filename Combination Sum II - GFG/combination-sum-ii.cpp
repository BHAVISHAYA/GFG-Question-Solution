//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void samadhaan(int i, int sum, int k, vector<int> &nums, vector<int> &subSet, vector<vector<int>> &ans) {
        if(sum == k) {
            ans.push_back(subSet);
            return;
        }
        if(sum > k) return;
        if(i >= nums.size()) return;
        
        // Pick
        sum += nums[i];
        subSet.push_back(nums[i]);
        samadhaan(i + 1, sum, k, nums, subSet, ans);
        sum -= nums[i];
        subSet.pop_back();
        
        // Not Pick
        while((i + 1) < nums.size() && nums[i] == nums[i + 1]) i++;
        samadhaan(i + 1, sum, k, nums, subSet, ans);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(), arr.end());
        vector<int> ss;
        vector<vector<int>> ans;
        samadhaan(0, 0, k, arr, ss, ans);
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends