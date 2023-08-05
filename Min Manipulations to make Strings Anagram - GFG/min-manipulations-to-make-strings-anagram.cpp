//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minManipulation (int N, string S1, string S2)
{
    // your code here
    int ans = 0;
    unordered_map<char, int> m;
    for(auto &value : S1) {
        m[value]++;
    }
    for(auto &value : S2) {
        if(m.find(value) != m.end()) {
            if(m[value] > 0) 
            m[value]--;
        }
    }
    for(auto &value : m) {
        ans += value.second;
    }
    return ans;
}