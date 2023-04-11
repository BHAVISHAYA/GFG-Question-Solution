//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool binarySearch(vector<int> &nums, int toFind) {
        int lo = 0, hi = nums.size() - 1;
        while(hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if(nums[mid] < toFind)
            lo = mid + 1;
            else 
            hi = mid;
        }
        if(nums[lo] == toFind) return true;
        if(nums[hi] == toFind) return true;
        return false;
    }
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        for(int i = 0 ; i < matrix.size() ; i++) 
        if(binarySearch(matrix[i], x)) return true;
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends