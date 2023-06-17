#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;

int f(int n,int m,vector<int> v){
    int dp[n+2][m+2];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int x=1;x<=m;x++){
            if(i == 1){
                if(v[i] == 0 or v[i] == x){
                    dp[i][x] = 1;
                }else dp[i][x] = 0;
            }else{
                if(v[i] == 0 or v[i] == x){
                    dp[i][x] = (dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1])%mod;
                }else dp[i][x] = 0;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans = (ans + dp[n][i] % mod) % mod;
    }
    return ans;
}

int32_t main(){
    int n,m;cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)cin >> v[i];
    cout << f(n,m,v) << endl;
    return 0;
}