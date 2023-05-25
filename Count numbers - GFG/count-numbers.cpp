//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool contain3OrNot(int n) {
        while(n > 0) {
            if(n % 10 == 3) return true;
            n = n / 10;
        }
        return false;
    }
    int count(int N){ 
        // code here
        int ct = 0;
        for(int i = 1 ; i <= N ; i++) {
            if(contain3OrNot(i) == false) 
            ct++;
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends