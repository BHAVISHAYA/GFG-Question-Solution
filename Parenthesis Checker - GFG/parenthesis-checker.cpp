//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    unordered_map<char, int> m = {{'(', 1}, {')', - 1}, {'{', 2}, {'}', -2}, {'[', 3}, {']', -3}};

    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(auto &value : x) {
            if(st.empty()) {
                if(m[value] < 0) return false;
                st.push(value);
            }
            else {
                if(m[value] > 0) 
                st.push(value);
                else if(m[st.top()] + m[value] != 0) return false;
                else if(m[st.top()] + m[value] == 0) 
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends