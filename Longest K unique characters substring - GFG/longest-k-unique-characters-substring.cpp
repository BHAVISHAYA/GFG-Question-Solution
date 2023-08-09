//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        int ans = INT_MIN;
        unordered_map<char, int> m;
        int slow = 0, fast = 0;
        while(fast < s.size()) {
            m[s[fast]]++;
            if(m.size() < k) {
                fast++;
            }
            else if(m.size() == k) {
                ans = max(ans, fast - slow + 1);
                fast++;
            }
            else if(m.size() > k) {
                while(m.size() > k) {
                    m[s[slow]]--;
                    if(m[s[slow]] == 0) {
                        m.erase(s[slow]);
                    }
                    slow++;
                }
                fast++;
            }
        }
        if(ans < 0) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends