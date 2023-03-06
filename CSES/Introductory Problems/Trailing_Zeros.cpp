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
    ll f = 5;
    ll ans = 0;
    while(f <= n){
        ans += (n/f);
        f *= 5;
    }
    cout << ans << endl;
    return 0;
}