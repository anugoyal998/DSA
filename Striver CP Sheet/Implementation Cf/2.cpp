#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;cin >> n;
    vector<vector<int>> v;
    for(int i=0; i<n;i++){
        int l,r,c;cin >> l >> r >> c;
        v.push_back({l,r,c});
    }
    cout << v[0][2] << "\n";
    int mine = 0, maxe = 0;
    for(int i=1;i<n;i++){
        if(v[i][0] < v[mine][0]){
            mine = i;
        }else if(v[i][0] == v[mine][0] and v[i][2] < v[mine][2]){
            mine = i;
        }
        if(v[i][1] > v[maxe][1]){
            maxe = i;
        }else if(v[i][1] == v[maxe][1] and v[i][2] < v[maxe][2]){
            maxe = i;
        }

        if(mine == maxe){cout << v[mine][2] << "\n"; continue;}

        if(maxe == i){
            if(v[i][0] == v[mine][0])mine = i;
        }else if(mine == i){
            if(v[i][1] == v[maxe][1])maxe = i;
        }

        if(mine == maxe)cout << v[mine][2] << "\n";
        else cout << v[mine][2] + v[maxe][2] << "\n";
    }
}

int32_t main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}