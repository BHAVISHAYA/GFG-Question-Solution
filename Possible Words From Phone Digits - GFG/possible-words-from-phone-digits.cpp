//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> v;
    vector<string> p = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void combineWords(int a[], int n, string sub, int i) {
        if(i == n) {
            v.push_back(sub);
            return;
        }
        for(int j = 0 ; j < p[a[i]].size() ; j++) {
            combineWords(a, n, sub + p[a[i]][j], i + 1);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        string temp = "";
        combineWords(a, N, temp, 0);
        return v;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends