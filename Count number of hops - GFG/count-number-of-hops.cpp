//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        long long int M = 1e9 + 7;
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        long long int ct = 0, one = 1, two = 1, three = 2;
        for(int i = 3 ; i <= n ; i++) {
            ct = (one + two + three) % M;
            one = two;
            two = three;
            three = ct;
        }
        return ct;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends