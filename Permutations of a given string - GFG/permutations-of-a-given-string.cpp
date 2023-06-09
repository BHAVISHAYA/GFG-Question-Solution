//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void help(int pos, string &s, set<string> &ans) {
	        if(pos >= s.size()) {
	            ans.insert(s);
	            return;
	        }
	        
	        for(int i = pos ; i < s.size() ; i++) {
	            swap(s[i], s[pos]);
	            help(pos + 1, s, ans);
	            swap(s[i], s[pos]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> v;
		    set<string> ans;
		    help(0, S, ans);
		    for(auto &value : ans) {
		        v.push_back(value);
		    }
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends