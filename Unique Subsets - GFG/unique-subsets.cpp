//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void powerSet(int i, vector<int> &nums, vector<int> &subSet, vector<vector<int>> &ans) {
        if(i >= nums.size()) {
            sort(subSet.begin(), subSet.end());
            ans.push_back(subSet);
            return;
        }

        // Include the ith element
        subSet.push_back(nums[i]);
        powerSet(i + 1, nums, subSet, ans);
        // Undo the change
        subSet.pop_back();
        // Check if ith element is equal to (i + 1)th element or not if YES then increment (i)
        while((i + 1) < nums.size() && nums[i] == nums[i + 1]) i++; 
        powerSet(i + 1, nums, subSet, ans);
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> subSet;
        powerSet(0, arr, subSet, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends