//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr, arr + n);
        vector<long long int> v1, v2;
        v1.push_back(0);
        v2.push_back(0);
        if(n % 2 == 0) {
            for(int i = 0 ; i < n ; i++) {
                if(i % 2 == 0) 
                v1.push_back(arr[i]);
                else 
                v2.push_back(arr[i]);
            }
        }
        else {
            v2.push_back(0);
            for(int i = 0 ; i < n ; i++) {
                if(i % 2 == 0) 
                v1.push_back(arr[i]);
                else 
                v2.push_back(arr[i]);
            }
        }
        long long int sum = v1[v1.size() - 1] + v2[v2.size() - 1];
        for(int i = v1.size() - 1 ; i > 0 ; i--) {
            if(sum <= 9) {
                v1[i] = sum;
                v1[i - 1] = v1[i - 1] + v2[i - 1];
                sum = v1[i - 1];
            }
            else {
                v1[i] = sum % 10;
                sum = sum / 10;
                v1[i - 1] = v1[i - 1] + v2[i - 1] + sum;
                sum = v1[i - 1];
            }
        }
        if(v1[0] == 0) 
        v1.erase(v1.begin() + 0);
        sum = 0;
        for(int i = 0 ; i < v1.size() ; i++) 
        sum = sum * 10 + v1[i];
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends