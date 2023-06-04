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
    unordered_map<int, string> m = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    
    void help(int i, int n, int a[], string &temp, vector<string> &ans) {
        if(i >= n) {
            ans.push_back(temp);
            return;
        }
        
        string str = m[a[i]];
        for(int j = 0 ; j < str.size() ; j++) {
            temp.push_back(str[j]);
            help(i + 1, n, a, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        string temp;
        help(0, N, a, temp, ans);
        return ans;
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