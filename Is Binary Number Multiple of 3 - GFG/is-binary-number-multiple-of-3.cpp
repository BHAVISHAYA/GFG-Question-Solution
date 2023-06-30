//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s) {
	    long long int sum2 = 0, j = 0;
	    for(int i = s.size() - 1 ; i >= 0 ; i--) {
	        if(s[i] == '1') {
	            if(j & 1) 
	            sum2 += 2;
	            else 
	            sum2 += 1;
	        }
	        j++;
	    }
	    if(sum2 % 3 == 0) return 1;
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends