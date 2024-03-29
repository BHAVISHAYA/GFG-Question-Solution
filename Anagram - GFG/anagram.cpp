//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        unordered_map<char, int> m;
        for(auto &value : a) {
            m[value]++;
        } 
        for(auto &value : b) {
            if(m.find(value) == m.end()) return false;
            else {
                if(m[value] > 0) {
                    m[value]--;
                    if(m[value] == 0) 
                    m.erase(value);
                }
                else 
                return false;
            }
        }
        if(m.size() == 0) return true;
        return false;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends