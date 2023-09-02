//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long, long> p;
        bool flag = true;
        for(int i = 0 ; i < v.size() ; i++) {
            if(v[i] == x) {
                p.first = i;
                flag = false;
                break;
            }
        }
        if(flag == false) {
            for(int i = v.size() - 1 ; i >= 0 ; i--) {
                if(v[i] == x) {
                    p.second = i;
                    break;
                }
            }
        }
        else {
            p.first = -1;
            p.second = -1;
        }
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends