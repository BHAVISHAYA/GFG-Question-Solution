//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    vector<int> num1, num2;
        num1.push_back(0);
        num2.push_back(0);
        if(a.size() < b.size()) {
            int extra = b.size() - a.size();
            while(extra--) {
                num1.push_back(0);
            }
        }
        else {
            int extra = a.size() - b.size();
            while(extra--) {
                num2.push_back(0);
            }
        }
        for(int i = 0 ; i < a.size() ; i++) {
            num1.push_back((int)a[i] - 48);
        }
        for(int i = 0 ; i < b.size() ; i++) {
            num2.push_back((int)b[i] - 48);
        }
        int carry = 0;
        for(int i = num1.size() - 1 ; i >= 0 ; i--) {
            if(num1[i] + num2[i] + carry == 0) {
                num1[i] = 0;
                carry = 0;
            }
            else if(num1[i] + num2[i] + carry == 1) {
                num1[i] = 1;
                carry = 0;
            }
            else if(num1[i] + num2[i] + carry == 2) {
                num1[i] = 0;
                carry = 1;
            }
            else if(num1[i] + num2[i] + carry == 3) {
                num1[i] = 1;
                carry = 1;
            } 
        }
        while(num1[0] == 0 && num1.size() > 1) {
            if(num1[0] == 0)
            num1.erase(num1.begin() + 0);
        }
        a.clear();
        for(int i = 0 ; i < num1.size() ; i++) {
            a += to_string(num1[i]);
        }
        return a;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends