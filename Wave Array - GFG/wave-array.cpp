//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        vector<int> v;
        for(int i = 0 ; i < arr.size() ; i++) {
            if(i % 2 == 0) {
                v.push_back(arr[i]);
            }
            else {
                arr[i - 1] = arr[i];
            }
        }
        int j = 0;
        for(int i = 0 ; i < arr.size() ; i++) {
            if(i % 2 != 0) {
                arr[i] = v[j];
                j++;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        sort(a.begin(),a.end());
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}
// } Driver Code Ends