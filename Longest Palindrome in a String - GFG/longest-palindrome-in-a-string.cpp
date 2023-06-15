//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string A) {
        // code here
        int n = A.length() , len = A.length();
       while(len > 0){
           int j = 0;
           while(j+len <= n){
               int start = j,end = j+len-1;
               while(start < end){
                if(A[start] != A[end]) break;
                start++; end--;
               }
               if(start >= end){
                   return A.substr(j  , len);
               }
               j++;
           }
           len--;
       }
       string res = "";
       return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends