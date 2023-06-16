//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    vector<int> subSetSum(int n, int arr[], int range) {
        bool shraddha[n + 1][range + 1];
        for(int i = 0 ; i < n + 1 ; i++) {
            for(int j = 0 ; j < range + 1 ; j++) {
                if(i == 0 && j != 0) {
                    shraddha[i][j] = false;
                }
                else if(j == 0) {
                    shraddha[i][j] = true;
                }
                else if(arr[i - 1] <= j) {
                    shraddha[i][j] = shraddha[i - 1][j - arr[i - 1]] || shraddha[i - 1][j];
                }
                else {
                    shraddha[i][j] = shraddha[i - 1][j];
                }
            }
        }
        vector<int> v;
        for(int i = 0 ; i <= range / 2 ; i++) {
            if(shraddha[n][i] == true) 
            v.push_back(i);
        }
        return v;
    } 
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range = accumulate(arr, arr + n, 0);
	    vector<int> ans = subSetSum(n, arr, range);
	    int mn = INT_MAX;
	    for(int i = 0 ; i < ans.size() ; i++) {
	        mn = min(mn, range - 2 * ans[i]);
	    }
	    return mn;
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends