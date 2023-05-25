//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    bool divisors(int n, int m) {
        int ct = 0;
        for(int i = 1 ; i * i <= n ; i++) {
            if(n % i == 0) {
                ct++;
                if(ct > m) return false;
                if(i != (n / i)) 
                ct++;
                if(ct > m) return false;
            }
        }
        if(ct == m) return true;
        return false;
    }
    int count(int A,int B,int N){ 
        // code 
        int cnt = 0;
        for(int i = A ; i <= B ; i++) {
            if(divisors(i, N))
            cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,N;
        cin>>A>>B>>N;
        Solution ob;
        cout << ob.count(A,B,N) << endl;
    }
    return 0; 
}
// } Driver Code Ends