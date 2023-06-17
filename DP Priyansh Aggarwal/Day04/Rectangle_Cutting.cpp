#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int dp[501][501];

int f(int a,int b){
    if(a<=0 or b<=0)return 0;
    if(dp[a][b] != -1)return dp[a][b];
    if(a==b)return dp[a][b] = 0;
    int ans = INT_MAX;
    for(int i=1;i<=(a/2);i++){
        int x = f(i,b), y = f(a-i,b);
        if(x == INT_MAX or y == INT_MAX)continue;
        ans = min(ans,1+x+y);
    }
    for(int i=1;i<=(b/2);i++){
        int x = f(a,i), y = f(a,b-i);
        if(x == INT_MAX or y == INT_MAX)continue;
        ans = min(ans,1+x+y);
    }
    return dp[a][b] = ans;
}

int main(){
    int a,b;cin >> a >> b;
    memset(dp,-1,sizeof(dp));
    cout << f(a,b) << endl;
    return 0;
}