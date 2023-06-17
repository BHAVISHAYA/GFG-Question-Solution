//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    vector<int> maxLeft(int n, int nums[]) {
        vector<int> ans(n);
        ans[0] = nums[0];
        for(int i = 1 ; i < n ; i++) {
            ans[i] = max(ans[i - 1], nums[i]);
        }
        return ans;
    }
    
    vector<int> maxRight(int n, int nums[]) {
        vector<int> ans(n);
        ans[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--) {
            ans[i] = max(ans[i + 1], nums[i]);
        }
        return ans;
    }
    
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> mxL = maxLeft(n, arr);
        vector<int> mxR = maxRight(n, arr);
        vector<int> water(n);
        for(int i = 0 ; i < n ; i++) {
            water[i] = min(mxL[i], mxR[i]) - arr[i];
        }
        long long int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += water[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends