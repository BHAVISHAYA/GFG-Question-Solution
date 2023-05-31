//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Geeks {
  public:
  static void greaterKSorted(vector<int>&arr, int k) {
      set<int> st;
      for(int i = 0 ; i < arr.size() ; i++) {
          if(arr[i] >= k)
          st.insert(arr[i]);
      }
      vector<int> v;
      if(st.size() == 0) 
      v.push_back(-1);
      else {
          for(auto &value : st) {
              v.push_back(value);
          }
      }
      for(int i = 0 ; i < v.size() ; i++) {
          cout << v[i] << " ";
      }
  }
  static void smallerKSorted(vector<int>&arr, int k) {
      set<int> s;
      for(int i = 0 ; i < arr.size() ; i++) {
          if(arr[i] < k) 
          s.insert(arr[i]);
      }
      vector<int> p;
      if(s.size() == 0) 
      p.push_back(-1);
      else {
          for(auto &value : s) {
              p.push_back(value);
          }
      }
      for(int i = 0 ; i < p.size() ; i++) {
          cout << p[i] << " ";
      }
  }
};

//{ Driver Code Starts.
int main() {
    
    int t; 
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n;
        cin >> k;
        
        vector<int>arr;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        Geeks obj;
        obj.greaterKSorted(arr, k);
        cout<<endl;
        obj.smallerKSorted(arr, k);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends