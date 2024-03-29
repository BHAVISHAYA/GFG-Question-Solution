//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    string ans;
	    unordered_map<char, bool> m;
	    for(int i = 0 ; i < str.size() ; i++) {
	        m[str[i]] = false;
	    }
	    for(int i = 0 ; i < str.size() ; i++) {
	        if(m[str[i]] == false) {
	            ans.push_back(str[i]);
	            m[str[i]] = true;
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends