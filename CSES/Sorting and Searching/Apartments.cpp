#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,m,k;
    cin >> n >> m >> k;
    multiset<int> a,b;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    int ans = 0;
    for(auto i:b){
        auto it = a.lower_bound(i-k);
        if(it == a.end())continue;
        int diff = abs(i - *it);
        if(diff <= k){
            ans++;
            a.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}