//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        vector<int> v;
        unordered_map<int, int> m;
        for(auto &value : nums) {
            m[value]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto &value : m) {
            minHeap.push({value.second, value.first});
            if(minHeap.size() > k)
            minHeap.pop();
        }
        vector<int> ans;
        vector<pair<int, int>> p;
        while(!minHeap.empty()) {
            p.push_back({minHeap.top().first, minHeap.top().second});
            minHeap.pop();
        }
        sort(p.rbegin(), p.rend());
        for(int i = 0 ; i < p.size() ; i++) {
            ans.push_back(p[i].second);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends