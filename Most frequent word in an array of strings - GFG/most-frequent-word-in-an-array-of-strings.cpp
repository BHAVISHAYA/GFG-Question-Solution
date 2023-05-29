//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        if(n == 1) return arr[0];
        unordered_map<string, int> m;
        for(int i = 0 ; i < n ; i++) {
            m[arr[i]]++;
        }
        unordered_map<string, int> mp;
        for(int i = 0 ; i < n ; i++) {
            mp.insert({arr[i], i});
        }
        vector<pair<int, string>> p;
        for(int i = 0 ; i < n ; i++) {
            p.push_back({m[arr[i]], arr[i]});
        }
        sort(p.rbegin(), p.rend());
        int ans = 0, l = p.size();
        for(int i = 0 ; i < p.size() - 1 ; i++) {
            if(p[i].first != p[i + 1].first) {
                ans = i + 1;
                while(ans != l) {
                    p.pop_back();
                    ans++;
                }
                break;
            }
        }
        int max = -1;
        for(int i = 0 ; i < p.size() ; i++) {
            if(max < mp[p[i].second]) {
                max = mp[p[i].second];
            }
        }
        return arr[max];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends