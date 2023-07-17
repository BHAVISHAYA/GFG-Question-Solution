//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> m;
		    queue<char> Q;
		    string res = "";
		    for(auto &value : A) {
		        m[value]++;
		        if(m[value] == 1) {
		            Q.push(value);
		        }
		        while(!Q.empty() && m[Q.front()] > 1) {
		            Q.pop();
		        }
		        if(Q.empty()) {
		            res.push_back('#');
		        }
		        else {
		            res.push_back(Q.front());
		        }
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends