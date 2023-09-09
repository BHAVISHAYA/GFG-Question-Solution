//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        vector<int> one, two;
        one.push_back(0);
        two.push_back(0);
        if(X.size() < Y.size()) {
            int e = Y.size() - X.size();
            while(e--) 
            one.push_back(0);
        }
        else {
            int e = X.size() - Y.size();
            while(e--)
            two.push_back(0);
        }
        for(auto &value : X) 
        one.push_back((int)value - 48);
        for(auto &value : Y) 
        two.push_back((int)value - 48);
        int sum = one[one.size() - 1] + two[two.size() - 1];
        for(int i = one.size() - 1 ; i > 0 ; i--) {
            if(sum <= 9) {
                one[i] = sum;
                one[i - 1] = one[i - 1] + two[i - 1];
                sum = one[i - 1];
            }
            else {
                one[i] = sum % 10;
                sum = sum / 10;
                one[i - 1] = one[i - 1] + two[i - 1] + sum;
                sum = one[i - 1];
            }
        }
        while(one[0] == 0 && one.size() > 1) {
            if(one[0] == 0)
            one.erase(one.begin() + 0);
        }
        X.clear();
        for(int i = 0 ; i < one.size() ; i++) {
            X += to_string(one[i]);
        }
        return X;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends