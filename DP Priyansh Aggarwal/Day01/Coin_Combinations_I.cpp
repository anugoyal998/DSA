#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

const ll mod = 1e9+7;

int main(){
    int n,x;
    cin >> n >> x;
    vi v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    sort(v.begin(),v.end());
    ll dp[x+1];
    dp[0] = 1;
    for(int i=1;i<v[0] and i<=x;i++)dp[i] = 0;
    for(int i=v[0];i<=x;i++){
        ll sum = 0;
        for(int j=0;j<n;j++){
            int y = i - v[j];
            if(y < 0)break;
            sum = (sum + dp[y]) % mod;
        }
        dp[i] = sum;
    }
    cout << dp[x] << endl;
    return 0;
}