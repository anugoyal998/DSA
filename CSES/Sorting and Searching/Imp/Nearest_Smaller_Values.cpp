#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans(n,0);
    stack<int>st;
    st.push(0);
    for(int i=1; i<n; i++){
        while(st.size() and arr[i] <= arr[st.top()])st.pop();
        if(st.size() == 0)ans[i] = 0;
        else ans[i] = st.top()+1;
        st.push(i);
    }
    for(auto i:ans)cout << i << " ";
    return 0;
}