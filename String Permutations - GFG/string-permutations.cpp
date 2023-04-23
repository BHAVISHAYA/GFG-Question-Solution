//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> v;
    void permute(int i, string &s) {
        if(i == s.size() - 1) {
            v.push_back(s);
            return;
        }
        for(int j = i ; j < s.size() ; j++) {
            swap(s[i], s[j]);
            permute(i + 1, s);
            swap(s[j], s[i]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        permute(0, S);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends