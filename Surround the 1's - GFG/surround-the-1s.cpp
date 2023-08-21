//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int count_zero(int i, int j, int n, int m, vector<vector<int>> &matrix) {
        int ct = 0;
        if(i - 1 >= 0 && matrix[i - 1][j] == 0)
        ct++;
        if(i - 1 >= 0 && j - 1 >= 0 && matrix[i - 1][j - 1] == 0) 
        ct++; 
        if(i - 1 >= 0 && j + 1 < m && matrix[i - 1][j + 1] == 0)
        ct++; 
        if(j - 1 >= 0 && matrix[i][j - 1] == 0) 
        ct++; 
        if(j + 1 < m && matrix[i][j + 1] == 0)
        ct++; 
        if(i + 1 < n && matrix[i + 1][j] == 0) 
        ct++; 
        if(i + 1 < n && j - 1 >= 0 && matrix[i + 1][j - 1] == 0) 
        ct++; 
        if(i + 1 < n && j + 1 < m && matrix[i + 1][j + 1] == 0) 
        ct++;
        return ct;
    }
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int res = 0;
        for(int i = 0 ; i < matrix.size() ; i++) {
            for(int j = 0 ; j < matrix[0].size() ; j++) {
                if(matrix[i][j] == 1) {
                    int cnt = count_zero(i, j, matrix.size(), matrix[0].size(), matrix);
                    if(cnt != 0 && cnt % 2 == 0)
                        res++;
                }
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends