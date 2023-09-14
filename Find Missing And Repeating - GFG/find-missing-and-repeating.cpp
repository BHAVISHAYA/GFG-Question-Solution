//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        // repeating number, missing number
        vector<int> v;
        unordered_map<int, int> m;
        for(int i = 0 ; i < arr.size() ; i++) {
            m[arr[i]]++;
        }
        int rep, miss;
        for(auto &value : m) {
            if(value.second == 2) {
                rep = value.first;
                break;
            }
        }
        for(int i = 1 ; i <= n ; i++) {
            if(m.find(i) == m.end()) {
                miss = i;
                break;
            }
        }
        v.push_back(rep);
        v.push_back(miss);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends