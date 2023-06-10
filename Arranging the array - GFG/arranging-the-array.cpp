//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            vector<int> po, ne;
            for(int i = 0 ; i < n ; i++) {
                if(arr[i] < 0)
                ne.push_back(arr[i]);
                else 
                po.push_back(arr[i]);
            }
            int j = 0;
            for(auto &value : ne) {
                arr[j] = value;
                j++;
            }
            for(auto &value : po) {
                arr[j] = value;
                j++;
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends