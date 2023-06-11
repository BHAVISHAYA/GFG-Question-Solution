//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<long long int> NSTR(long long int v[], int n) {
        long long int pseudoIndex = n;
        vector<long long int> index;
        stack<long long int> st;
        for(int i = n - 1 ; i >= 0 ; i--) {
            if(st.empty()) {
                index.push_back(pseudoIndex);
                st.push(i);
            }
            else {
                while(!st.empty()) {
                    if(v[st.top()] < v[i]) {
                        index.push_back(st.top());
                        st.push(i);
                        break;
                    }
                    else {
                        st.pop();
                        if(st.empty()) {
                            index.push_back(pseudoIndex);
                            st.push(i);
                            break;
                        }
                    }
                }
            }
        }
        reverse(index.begin(), index.end());
        return index;
    }
    
    vector<long long int> NSTL(long long int v[], int n) {
        long long int pseudoIndex = -1;
        vector<long long int> index;
        stack<long long int> st;
        for(int i = 0 ; i < n ; i++) {
            if(st.empty()) {
                index.push_back(pseudoIndex);
                st.push(i);
            }
            else {
                while(!st.empty()) {
                    if(v[st.top()] < v[i]) {
                        index.push_back(st.top());
                        st.push(i);
                        break;
                    }
                    else {
                        st.pop();
                        if(st.empty()) {
                            index.push_back(pseudoIndex);
                            st.push(i);
                            break;
                        }
                    }
                }
            }
        }
        return index;
    }

    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long int> NSTR_index = NSTR(arr, n);
        vector<long long int> NSTL_index = NSTL(arr, n);
        long long int max = 0;
        for(int i = 0 ; i < n ; i++) {
            if(max < ((NSTR_index[i] - NSTL_index[i] - 1) * arr[i])) {
                max = ((NSTR_index[i] - NSTL_index[i] - 1) * arr[i]);
            }
        }
        return max;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends