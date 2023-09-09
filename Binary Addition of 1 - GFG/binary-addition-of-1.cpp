//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string binaryAdd(int n, string s){
        // code here
        vector<int> one, two;
        one.push_back(0);
        two.push_back(0);
        for(int i = 0 ; i < n ; i++) {
            one.push_back((int)s[i] - 48);
            if(i == n - 1)
            two.push_back(1);
            else 
            two.push_back(0);
        }
        int carry = 0;
        for(int i = one.size() - 1 ; i >= 0 ; i--) {
            if(one[i] + two[i] + carry == 0) {
                one[i] = 0;
                carry = 0;
            }
            else if(one[i] + two[i] + carry == 1) {
                one[i] = 1;
                carry = 0;
            }
            else if(one[i] + two[i] + carry == 2) {
                one[i] = 0;
                carry = 1;
            }
            else if(one[i] + two[i] + carry == 3) {
                one[i] = 1;
                carry = 1;
            }
        }
        while(one[0] == 0 && one.size() > n) {
            if(one[0] == 0)
            one.erase(one.begin() + 0);
        }
        string ans = "";
        for(int i = 0 ; i < one.size() ; i++) {
            ans += to_string(one[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        
        Solution ob;
        cout<<ob.binaryAdd(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends