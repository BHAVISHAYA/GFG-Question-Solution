//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void samadhaan(int i, int k, int n, int sumTillNow, vector<int> &subSet, vector<vector<int>> &ans) {
        if(k == 0) {
            if(sumTillNow == n) {
                ans.push_back(subSet);
            }
            return;
        }
        if(sumTillNow > n) return;
        if(i > 9) return;
        
        // Pick 
        sumTillNow += i;
        subSet.push_back(i);
        samadhaan(i + 1, k - 1, n, sumTillNow, subSet, ans);
        sumTillNow -= i;
        subSet.pop_back();
        
        // Skip
        samadhaan(i + 1, k, n, sumTillNow, subSet, ans);
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int> ss;
        vector<vector<int>> ans;
        samadhaan(1, K, N, 0, ss, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends