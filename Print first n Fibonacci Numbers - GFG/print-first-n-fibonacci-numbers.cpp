//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long int> v;
        long long int a[n];
        a[0] = 0;
        a[1] = 1;
        for(int i = 0 ; i <= n ; i++){
            if(i == 1){
                v.push_back(a[i]);
            }
            else if(i > 1){
                a[i] = a[i - 1] + a[i - 2];
                v.push_back(a[i]);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends