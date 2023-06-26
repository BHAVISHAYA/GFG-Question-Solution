//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string> HiiShraddha;
	queue<string> shraddha;
	shraddha.push("1");
	for(int i = 0 ; i < N ; i++) {
	    string temp = shraddha.front();
	    HiiShraddha.push_back(temp);
	    shraddha.pop();
	    shraddha.push(temp + "0");
	    shraddha.push(temp + "1");
	}
	return HiiShraddha;
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends