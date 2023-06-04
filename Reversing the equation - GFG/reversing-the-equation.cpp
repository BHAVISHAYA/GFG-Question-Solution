//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    unordered_map<char, int> m = {{'+', 1}, {'-', 2}, {'*', 3}, {'/', 4}};
    string reverseEqn (string s)
        {
            //code here.
            string str = "";
            string tmp = "";
            for(int i = s.size() - 1 ; i >= 0 ; i--) {
                if(m[s[i]] != 1 && m[s[i]] != 2 && m[s[i]] != 3 && m[s[i]] != 4) {
                    tmp.push_back(s[i]);
                }
                else {
                    reverse(tmp.begin(), tmp.end());
                    str += tmp;
                    tmp.clear();
                    str.push_back(s[i]);
                }
            }
            if(tmp.size() != 0) {
                reverse(tmp.begin(), tmp.end());
                str += tmp;
            }
            return str;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends