//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long int sum = 0;
    void div(int n) {
        for(int i = 1 ; i * i <= n ; i++) {
            if(n % i == 0) {
                sumDiv(i);
                if(i != (n / i)) {
                    sumDiv(n / i);
                }
            }
        }
    }
    
    void sumDiv(int m) {
        for(int i = 1 ; i * i <= m ; i++) {
            if(m % i == 0) {
                sum += i;
                if(i != (m / i)) {
                    sum += (m / i);
                }
            }
        }
    }
    
    int sumOfDivisors(int N)
    {
        // Write Your Code here
        div(N);
        return sum;
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
        int ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends