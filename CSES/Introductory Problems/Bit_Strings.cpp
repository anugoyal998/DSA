#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

ll fastPow(ll a,ll b,ll m){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a) % m;
            b--;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin >> n;
    ll m = 1e9+7;
    cout << fastPow(2, n, m) << endl;
    return 0;
}