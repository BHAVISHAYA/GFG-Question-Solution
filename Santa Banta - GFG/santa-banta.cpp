//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    int prime[100001];
    
    bool isPrime(int n) {
        if(n == 1) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i = 5 ; i * i <= n ; i = i + 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    
    int ct = 0;
    void precompute(){
        for(int i = 2 ; i <= 1000000 ; i++) {
            if(isPrime(i)) {
                ct++;
                prime[ct] = i;
            }
        }
        prime[1] = -1;
    }
    
    int dfs(int node, vector<int> &visited, vector<vector<int>> &g) {
        visited[node] = 1;
        int cnt = 0;
        for(auto it : g[node]) {
            if(!visited[it])
            cnt += 1 + dfs(it, visited, g);
        }
        return cnt;
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        vector<int> visited(n + 1, 0);
        int maximum = -1;
        for(int j = 1 ; j <= n ; j++) {
            if(!visited[j]) {
                int value = 1 + dfs(j, visited, g);
                maximum = max(maximum, value);
            }
        }
        if(maximum == -1) return -1; 
        return prime[maximum];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends