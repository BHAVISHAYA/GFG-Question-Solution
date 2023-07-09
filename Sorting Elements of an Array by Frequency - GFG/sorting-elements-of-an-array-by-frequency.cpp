//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0 ; i < n ; i++) {
            m[arr[i]]++;
        }
        vector<pair<int, int>> p;
        for(auto &value : m) {
            p.push_back({value.second, value.first});
        }
        sort(p.rbegin(), p.rend());
        if(p.size() == 1) {
            int a = p[0].first;
            while(a--)
            ans.push_back(p[0].second);
        }
        else {
            stack<int> st;
            for(int i = 0 ; i < p.size() - 1 ; i++) {
                if(p[i].first == p[i + 1].first) {
                    int a = p[i].first;
                    while(a--) {
                        st.push(p[i].second);
                    }
                }
                else {
                    int a = p[i].first;
                    while(a--) {
                        st.push(p[i].second);
                    }
                    while(!st.empty()) {
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
            }
            if(p[p.size() - 1].first != p[p.size() - 2].first) {
                int a = p[p.size() - 1].first;
                while(a--)
                ans.push_back(p[p.size() - 1].second);
            }
            else {
                int a = p[p.size() - 1].first;
                while(a--) {
                    st.push(p[p.size() - 1].second);
                }
                while(!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends