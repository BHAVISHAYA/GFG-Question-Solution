//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long TowerOfHanoi(int n, int res, int from, int to, int aux) {
        if(n == 1) {
            cout << "move disk " << n << " from rod " << from << " to rod " << aux << endl;
            return res;
        }
        TowerOfHanoi(n - 1, res, from, aux, to);
        cout << "move disk " << n << " from rod " << from << " to rod " << aux << endl;
        TowerOfHanoi(n - 1, res, to, from, aux);
    }
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        long long res = pow(2, N) - 1;
        return TowerOfHanoi(N, res, from, aux, to);
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends