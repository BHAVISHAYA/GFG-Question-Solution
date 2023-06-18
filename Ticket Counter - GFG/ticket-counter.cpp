//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // Using Two Pointer 
        int slow = 1, fast = N;
        while(slow < fast) {
            int sz = K;
            while(slow < fast && sz-- > 0) 
            slow++;
            sz = K;
            while(slow < fast && sz-- > 0) 
            fast--;
        }
        return slow;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends