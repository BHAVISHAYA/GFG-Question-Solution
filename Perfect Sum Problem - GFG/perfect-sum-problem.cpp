//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long int M = pow(10, 9) + 7;
	int countOfSubSetSum(int n, int sum, vector<int> &nums) {
        int dp[n + 1][sum + 1];
        for(int i = 0 ; i < n + 1; i++) {
            for(int j = 0 ; j < sum + 1 ; j++) {
                // Initialization :-> 
                if(i == 0 && j != 0) {
                    dp[i][j] = 0;
                }
                else if(j == 0) {
                    dp[i][j] = 1;
                }
                // Main Logic :->
                else if(nums[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]) % M;
                }
                else {
                    dp[i][j] = (dp[i - 1][j]) % M;
                }
            }
        }
        return dp[n][sum] % M; 
    }
    
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<int> nums;
        for(int i = 0 ; i < n ; i++) {
            nums.push_back(arr[i]);
        }
        sort(nums.rbegin(), nums.rend());
        return countOfSubSetSum(n, sum, nums);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends