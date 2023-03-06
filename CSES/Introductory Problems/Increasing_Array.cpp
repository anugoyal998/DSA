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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++)cin >> v[i];
    ll ans = 0;
    for(int i=1;i<n;i++){
        if(v[i] < v[i-1]){
            ll diff = v[i-1] - v[i];
            ans = ans + diff;
            v[i] = v[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}