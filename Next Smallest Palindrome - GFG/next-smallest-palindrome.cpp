//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    vector<int> ans;
	    int carry;
	    int done = 0;
	    for(int i = n / 2 ; i < n ; i++) {
	        if(num[i] < num[n - i - 1]) {
	            num[i] = num[n - i - 1]; 
	            for(int j = i + 1 ; j < n ; j++) {
	                num[j] = num[n - j - 1];
	            }
	            done = 1;
	            break;
	        }
	        else if(num[i] > num[n - i - 1]) {
	            break;
	        }
	    }
	    if(done == 1) {
	        for(int i = 0 ; i < n ; i++) {
	            ans.push_back(num[i]);
	        }
	        return ans;
	    }
	    else {
	        carry = 1;
	        for(int i = (n - 1) / 2 ; i >= 0 ; i--) {
	            if(num[i] + carry == 10) {
	                num[i] = 0;
	                carry = 1;
	            }
	            else {
	                num[i]++;
	                carry = 0;
	                break;
	            }
	        }
	    }
	    if(carry == 1) {
	        ans.push_back(1);
	    }
	    for(int i = 0 ; i < n ; i++) {
	        ans.push_back(num[i]);
	    }
	    if(carry == 1) {
	        n++;
	    }
	    for(int i = (n + 1) / 2 ; i < n ; i++) {
	        ans[i] = ans[n - i - 1];
	    }
	    return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends