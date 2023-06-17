#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007
 
vector<ll> pref_sum;
 
ll sum(int i,int j){
    --i;
    int start = 0, end = pref_sum.size()-1;
    if(j < 0)return 0;
    ll ans = pref_sum[j];
    if(i >= 0)ans -= pref_sum[i];
    return ans;
}
 
int f(int i,int j,vi arr,vvi &dp){
    if(i > j)return 0;
    if(i == j)return arr[i];
    if(dp[i][j] != -1)return dp[i][j];
    int op1 = arr[i] + sum(i+1,j) - f(i+1,j,arr,dp);
    int op2 = arr[j] + sum(i,j-1) - f(i,j-1,arr,dp);
    return dp[i][j] = max(op1,op2);
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
 
    int n;
    cin >> n;
    vi arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
 
    pref_sum = vector<ll>(n,0);
    pref_sum[0] = arr[0];
    for(int i=1;i<n;i++)
        pref_sum[i] = pref_sum[i-1] + arr[i];
    
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    // cout << f(0,n-1,arr,dp) << endl;
 
    for(int i=0;i<n;i++)
        dp[i][i] = arr[i];
    
    for(int k=2;k<=n;k++){
        for(int i=0;i<=n-k;i++){
            int j = i + k - 1;
            ll op1 = arr[i] + sum(i+1,j) - dp[i+1][j];
            ll op2 = arr[j] + sum(i,j-1) - dp[i][j-1];
            dp[i][j] = max(op1,op2);
        }
    }
 
    cout << dp[0][n-1] << endl;
    
 
    return 0;
}