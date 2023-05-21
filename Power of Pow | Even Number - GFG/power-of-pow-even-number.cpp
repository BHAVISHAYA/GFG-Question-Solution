//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int sum_of_square_evenNumbers(long long int n)
		{
		    // Code here
		    long long int sum = 0;
		    int j = 2;
		    for(int i = 1 ; i <= n ; i++) {
		        sum += pow(j, 2);
		        j = j + 2;
		    }
		    return sum;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.sum_of_square_evenNumbers(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends