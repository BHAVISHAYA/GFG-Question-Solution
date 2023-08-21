//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
        vector<int> A, B;
        A.push_back(0);
        B.push_back(0);
        if(n < m) {
            int extra = m - n;
            while(extra--) {
                A.push_back(0);
            }
        }
        else if(m < n) {
            int extra = n - m;
            while(extra--) {
                B.push_back(0);
            }
        }
        for(int i = 0 ; i < n ; i++) {
            A.push_back(a[i]);
        }
        for(int i = 0 ; i < m ; i++) {
            B.push_back(b[i]);
        }
        int sum = A[A.size() - 1] + B[B.size() - 1];
        for(int i = A.size() - 1 ; i > 0 ; i--) {
            if(sum <= 9) {
                A[i] = sum;
                A[i - 1] = A[i - 1] + B[i - 1];
                sum = A[i - 1];
            }
            else {
                A[i] = sum % 10;
                sum = sum / 10;
                A[i - 1] = A[i - 1] + B[i - 1] + sum;
                sum = A[i - 1];
            }
        }
        while(true) {
            if(A[0] == 0)
            A.erase(A.begin() + 0);
            else 
            break;
        }
        string ans = "";
        for(int i = 0 ; i < A.size() ; i++) {
            ans += to_string(A[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends