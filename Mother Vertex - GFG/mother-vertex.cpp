//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> vis(V, false);
        int ans = -1;
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                ans = i;
            }
        }
        vector<bool> vis2(V, false);
        dfs(ans, adj, vis2);
        for(bool value : vis2) {
            if(!value)
            return -1;
        }
        return ans;
	}
	void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;
        for(int &value : adj[node]) {
            if(!vis[value]) {
                dfs(value, adj, vis);
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends