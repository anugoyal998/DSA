#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][10][2][2];

int f(string s,int n,int x,bool leading,bool tight){
    if(n==0)return 1;
    if(x != -1 and dp[n][x][leading][tight] != -1)return dp[n][x][leading][tight];
    int lb = 0;
    int ub = tight ? (s[s.length()-n] - '0') : 9;
    int ans = 0;
    for(int dig=lb;dig<=ub;dig++){
        if(dig == x and !leading)continue;
        ans += f(s,n-1,dig,(leading&(dig==0)),(tight&(dig==ub)));
    }
    return dp[n][x][leading][tight] = ans;
}

int32_t main(){
    int a,b;cin >> a >> b;a--;
    string u = to_string(a);
    string v = to_string(b);
    memset(dp,-1,sizeof dp);
    int ans2 = f(v,v.length(),-1,1,1);
    if(a<0){cout << ans2 << endl;return 0;}
    memset(dp,-1,sizeof dp);
    int ans1 = f(u,u.length(),-1,1,1);
    cout << ans2 - ans1 << endl;
    return 0;
}