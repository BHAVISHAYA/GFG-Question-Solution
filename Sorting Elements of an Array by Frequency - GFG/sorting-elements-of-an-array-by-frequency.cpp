#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0 ; i < n ; i++) cin >> nums[i];
        unordered_map<int, int> m;
        for(int i = 0 ; i < n ; i++) {
            m[nums[i]]++;
        }
        vector<pii> p;
        for(auto &value : m) {
            p.push_back({value.second, value.first});
        }
        sort(p.rbegin(), p.rend());
        if(p.size() == 1) {
            int a = p[0].first;
            while(a--)
            cout << p[0].second << " ";
            cout << endl;
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
                        cout << st.top() << " ";
                        st.pop();
                    }
                }
            }
            if(p[p.size() - 1].first != p[p.size() - 2].first) {
                int a = p[p.size() - 1].first;
                while(a--)
                cout << p[p.size() - 1].second << " ";
                cout << endl;
            }
            else {
                int a = p[p.size() - 1].first;
                while(a--) {
                    st.push(p[p.size() - 1].second);
                }
                while(!st.empty()) {
                    cout << st.top() << " ";
                    st.pop();
                }
                cout << endl;
            }
        }
    }
}