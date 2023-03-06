#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

bool help(vector<ll> v,ll mid,ll t){
    ll cnt = 0;
    for(auto i:v){
        cnt += (mid/i);
        if(cnt >= t)return true;
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,t;
    cin >> n >> t;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    ll ans = 1e18;
    ll start = 0, end = 1e18;
    while(start <= end){
        ll mid = start + (end-start)/2;
        if(help(v,mid,t)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}