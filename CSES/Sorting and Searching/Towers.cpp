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
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)cin >> v[i];
    multiset<int> s;
    int ans = 1;
    s.insert(v[0]);
    for(int i=1;i<n;i++){
        auto it = s.lower_bound(v[i]+1);
        if(it == s.end()){
            ans++;
            s.insert(v[i]);
        }else{
            s.erase(it);
            s.insert(v[i]);
        }
    }
    cout << ans << endl;
    return 0;
}