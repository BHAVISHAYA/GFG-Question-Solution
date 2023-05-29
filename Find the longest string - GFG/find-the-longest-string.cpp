//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        int max = 0;
        unordered_map<string, int> m;
        for(int i = 0 ; i < words.size() ; i++) {
            m[words[i]]++;
        }
        sort(words.begin(), words.end());
        vector<string> v;
        for(int i = 0 ; i < words.size() ; i++) {
            string s;
            int ct = 0;
            for(int j = 0 ; j < words[i].size() ; j++) {
                s.push_back(words[i][j]);
                if(m.find(s) != m.end())
                ct++;
                else 
                break;
                if(ct == words[i].size()) {
                    if(max < words[i].size())
                    max = words[i].size();
                    v.push_back(words[i]);
                    break;
                }
            }
        }
        if(v.size() == 0) return "";
        for(int i = 0 ; i < v.size() ; i++) {
            if(v[i].size() == max) return v[i];
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends