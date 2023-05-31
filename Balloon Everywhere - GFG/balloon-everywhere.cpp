//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char, int> m;
        for(auto &value : s) {
            m[value]++;
        }
        string str = "balloon";
        int j = 0, ct = 0;
        jump:
        for(int i = 0 ; i < str.size() ; i++) {
            if(m[str[i]] > 0)
            m[str[i]] = m[str[i]] - 1;
            else
            return ct;
        }
        ct++;
        goto jump;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends