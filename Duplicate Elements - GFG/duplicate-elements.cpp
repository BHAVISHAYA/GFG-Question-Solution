//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void SortedDuplicates(int n, vector<int> &arr) {
        // code here
        unordered_map<int, int> m;
        for(auto &value : arr) {
            m[value]++;
        }
        arr.clear();
        for(auto &value : m) {
            if(value.second > 1) 
            arr.push_back(value.first);
        }
        if(arr.size() == 0) 
        arr.push_back(-1);
        if(arr.size() > 1)
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < arr.size() ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        
        obj.SortedDuplicates(n, arr);
        
    }
}

// } Driver Code Ends