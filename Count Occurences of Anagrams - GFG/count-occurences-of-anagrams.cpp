//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int ans = 0, slow = 0, fast = 0, k = pat.size();
	    unordered_map<char, int> m;
	    for(auto &value : pat) {
	        m[value]++;
	    }
	    int count = m.size();
	    
	    while(fast < txt.size()) {
	        // calculation
	        if(m.find(txt[fast]) != m.end()) {
	            m[txt[fast]]--;
	            if(m[txt[fast]] == 0) 
	            count--;
	        }
	        
	        // When we don't hit the window
	        if(fast - slow + 1 < k) {
	            fast++;
	        }
	        
	        // When we hit the window
	        else if(fast - slow + 1 == k) {
	            if(count == 0) {
	                ans++;
	            }
	            
	            if(m.find(txt[slow]) != m.end()) {
	                m[txt[slow]]++;
	                if(m[txt[slow]] == 1) 
	                count++;
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
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends