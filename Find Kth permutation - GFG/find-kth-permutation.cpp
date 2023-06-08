//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // void help(int pos, string &str, vector<string> &ans) {
    //     if(pos >= str.size()) {
    //         ans.push_back(str);
    //         return;
    //     }
        
    //     for(int i = pos ; i < str.size() ; i++) {
    //         swap(str[i], str[pos]);
    //         help(pos + 1, str, ans);
    //         swap(str[i], str[pos]);
    //     }
    // }
    string kthPermutation(int n, int k)
    {
        // string s = "123456789";
        // int t = s.size() - n;
        // while(t--) {
        //     s.pop_back();
        // }
        // vector<string> ans;
        // help(0, s, ans);
        // sort(ans.begin(), ans.end());
        // return ans[k - 1];
        
        int fact = 1;
        vector<int> numbers;
        for(int i = 1 ; i < n ; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        while(true) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if(numbers.size() == 0) {
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends