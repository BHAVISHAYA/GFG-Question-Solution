//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {
        unordered_map<int, bool> m;
        for(int i = 0 ; i < n ; i++) {
            m[arr[i]] = true;
        }
        if(count(arr, arr + n, 0) == 0) {
            for(int i = 1 ; i <= n ; i++) {
                if(m[i] != true)
                return i;
            }
            return n + 1;
        }
        else {
            for(int i = 0 ; i <= n ; i++) {
                if(m[i] != true)
                return i;
            }
            return n + 1;
        }
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends