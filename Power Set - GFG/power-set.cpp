//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void samadhaan(int i, string &str, string &subSeq, vector<string> &ans) {
	        if(i >= str.size()) {
	            ans.push_back(subSeq);
	            return;
	        }
	        
	        // Pick
	        subSeq.push_back(str[i]);
	        samadhaan(i + 1, str, subSeq, ans);
	        subSeq.pop_back();
	        
	        // Not Pick
	        samadhaan(i + 1, str, subSeq, ans);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string str;
		    vector<string> ans;
		    if(s.size() == 1) {
		        ans.push_back(s);
		        return ans;
		    }
		    samadhaan(0, s, str, ans);
		    sort(ans.begin(), ans.end());
		    for(int i = 0 ; i < ans.size() - 1 ; i++) {
		        ans[i] = ans[i + 1];
		    }
		    ans.pop_back();
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends