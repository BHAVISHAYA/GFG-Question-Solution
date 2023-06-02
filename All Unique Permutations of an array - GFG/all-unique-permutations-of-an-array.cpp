//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void perm(int pos, vector<int> &ss, vector<vector<int>> &ans) {
        if(pos >= ss.size()) {
            ans.push_back(ss);
        }
        unordered_set<int> st;
        for(int i = pos ; i < ss.size() ; i++) {
            // So 
            if(st.find(ss[i]) != st.end()) continue; // If str[i] is again come then I should continue; 
            st.insert(ss[i]); // Inserted this element into the map and if next time same element is come then I should ignore it 
            swap(ss[i], ss[pos]);
            perm(pos + 1, ss, ans);
            swap(ss[i], ss[pos]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code her
        vector<vector<int>> ans;
        perm(0, arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends