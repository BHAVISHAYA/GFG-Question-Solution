//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++f
class Solution
{
    public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int countFractions(int n, int numerator[], int denominator[]){
        map<pair<int ,int>, int> m;
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            int d = gcd(numerator[i], denominator[i]);
            numerator[i] /= d;
            denominator[i] /=d;
            int x, y;
            x = numerator[i];
            y = denominator[i];
            int z = y - x;
            if(m.count({z, y}))
            ans += m[{z, y}];
            m[{x,y}]++;
        }
        return ans;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends