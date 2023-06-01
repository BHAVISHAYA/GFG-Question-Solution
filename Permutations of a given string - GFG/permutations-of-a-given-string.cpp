//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void perm(int pos, string &str, vector<string> &ans) {
	        if(pos >= str.size()) {
	            ans.push_back(str);
	        }
	        for(int i = pos ; i < str.size() ; i++) {
	            swap(str[i], str[pos]);
	            perm(pos + 1, str, ans);
	            swap(str[i], str[pos]); // Undo the change that we have made in the first step
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    perm(0, S, ans);
		    set<string> meraSamaadhaan;
		    for(int i = 0 ; i < ans.size() ; i++) {
		        meraSamaadhaan.insert(ans[i]);
		    }
		    ans.clear();
		    for(auto &value : meraSamaadhaan) {
		        ans.push_back(value);
		    }
		    return ans;
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