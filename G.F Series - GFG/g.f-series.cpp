//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long int power(long long int x, long long int n) {
        long long int res = 1;
        while(n > 0) {
            if(n & 1) 
            res = res * x;
            x = x * x;
            n = n >> 1;
        }
        return res;
    }
    void gfSeries(int N)
    {
        // Write Your Code here
        if(N <= 2) {
            cout << 0 << " " << 1 << endl;
        }
        else {
            long long int T[N];
            T[0] = 0;
            T[1] = 1;
            for(int i = 0 ; i < N ; i++) {
                if(i >= 2) 
                T[i] = power(T[i - 2], 2) - T[i - 1];
                cout << T[i] << " ";
            }
            cout << endl;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.gfSeries(N);
    }
    return 0;
}
// } Driver Code Ends