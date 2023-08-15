//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        int slow = 0, fast = n - 1;
        long long int leftSum = 0, rightSum = 0;
        while(slow < fast) {
            if(leftSum == rightSum) {
                leftSum += a[slow];
                rightSum += a[fast];
                slow++;
                fast--;
            }
            else if(rightSum < leftSum) {
                rightSum += a[fast];
                fast--;
            }
            else if(leftSum < rightSum) {
                leftSum += a[slow];
                slow++;
            }
        }
        if(slow == fast) {
            if(leftSum == rightSum) return slow + 1;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends