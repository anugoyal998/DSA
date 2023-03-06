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
    ll x;
    cin >> n >> x;
    vi v(n);
    for(int i=0; i<n; i++)cin >> v[i];
    sort(v.begin(),v.end());
    int ans = 0;
    int i = 0, j = n-1;
    while(i<=j){
        ll wt = v[i] + v[j];
        ans++;
        if(wt <= x){
            i++,j--;
        }else{
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}