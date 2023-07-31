//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        vector<int> l;
        int slow = 0, fast = 0;
        while(fast < n) {
            while(l.size() > 0 && l.back() < arr[fast]) {
                l.pop_back();
            }
            l.push_back(arr[fast]);
            
            if(fast - slow + 1 < k) {
                fast++;
            }
            
            else if(fast - slow + 1 == k) {
                if(l.size() > 0) {
                    ans.push_back(l.front());
                }
                
                if(l.front() == arr[slow]) {
                    l.erase(l.begin() + 0);
                }
                
                slow++;
                fast++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends