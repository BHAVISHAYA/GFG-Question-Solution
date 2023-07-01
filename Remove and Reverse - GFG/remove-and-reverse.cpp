//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<char, int> mp;
        for(int i = 0 ; i < S.size() ; i++) {
            mp[S[i]]++;
        }
        int rev = 0;
        jump:
        int flag = 0;
        if(rev % 2 == 0) {
            for(int i = 0 ; i < S.size() ; i++) {
                if(mp[S[i]] > 1) {
                    mp[S[i]] = mp[S[i]] - 1;
                    S.erase(S.begin() + i);
                    flag = 1;
                    rev++;
                    break;
                }
            }
        }
        else {
            for(int i = S.size() - 1 ; i >= 0 ; i--) {
                if(mp[S[i]] > 1) {
                    mp[S[i]] = mp[S[i]] - 1;
                    S.erase(S.begin() + i);
                    flag = 1;
                    rev++;
                    break;
                }
            }
        }
        if(flag == 0) { 
            if(rev % 2 != 0)
            reverse(S.begin(), S.end());
            return S; 
        }
        goto jump;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends