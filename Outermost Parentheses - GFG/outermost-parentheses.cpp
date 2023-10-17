//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string ans = "";
        stack<char> st;
        for(int i = 0 ; i < s.size() ; i++) {
            if(st.empty()) {
                if(s[i] == '(') {
                    st.push(s[i]);
                }
            }
            else {
                if(s[i] == ')') {
                    st.pop();
                    if(st.size() > 0) {
                        ans.push_back(s[i]);
                    }
                }
                else {
                    st.push(s[i]);
                    ans.push_back(s[i]);
                }
            }
        }
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
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends