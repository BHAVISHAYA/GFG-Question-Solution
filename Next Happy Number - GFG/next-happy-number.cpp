//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappyNum(int n) {
        if(n == 1 || n == 7) return 1;
        int sum = n, m = n;
        while(sum > 9) {
            sum = 0;
            while(m > 0) {
                int a = m % 10;
                sum += (a * a);
                m = m / 10;
            }
            if(sum == 1) return 1;
            m = sum;
        }
        if(sum == 7) return 1;
        return 0;
    }
    int nextHappy(int N) {
        int next = N + 1;
        int ans = next;
        while(true) {
            if(isHappyNum(next) == 1) {
                return next;
            }
            next++;
            ans = next;
        }
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends