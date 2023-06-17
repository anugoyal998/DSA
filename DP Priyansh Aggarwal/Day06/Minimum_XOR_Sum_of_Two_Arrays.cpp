#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long

class Solution {

    int countBits(int n){
        int ans = 0;
        while(n){
            n = (n&(n-1));
            ans++;
        }
        return ans;
    }
    // TC --> (n^2)*(2^n) --> 3211264
    int f(vi a,vi b,int i,ll bitmask,int n,vector<vector<ll>> &dp){
        if(bitmask == ((1<<n)-1) or i == n)return 0;
        if(dp[i][bitmask] != -1)return dp[i][bitmask];
        ll ans = 1e18;
        for(int j=0;j<n;j++){
            if(!(bitmask&(1<<j))){
                ans = min(ans,1LL*(a[i]^b[j])+f(a,b,i+1,(bitmask|(1<<j)),n,dp));
            }
        }
        return dp[i][bitmask] = ans;
    }
    // TC --> (n)*(2^n) --> 229376
    int f(vi a,vi b,ll bitmask,int n,vector<ll> &dp){
        if(bitmask == (1<<n)-1)return 0;
        if(dp[bitmask] != -1)return dp[bitmask];
        ll ans = 1e18;
        int i = countBits(bitmask);
        for(int j=0;j<n;j++){
            if(!(bitmask&(1<<j))){
                ans = min(ans,1LL*(a[i]^b[j])+f(a,b,(bitmask|(1<<j)),n,dp));
            }
        }
        return dp[bitmask] = ans;
    }
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<ll> dp((1<<n),-1);
        return f(a,b,0,n,dp);
        // vector<vector<ll>> dp(n,vector<ll>((1<<n),-1));
        // return f(a,b,0,0,n,dp);
    }
};

int main(){
    int n;cin >> n;
    vi a(n),b(n);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    Solution sol;
    cout << sol.minimumXORSum(a,b) << endl;
    return 0;
}