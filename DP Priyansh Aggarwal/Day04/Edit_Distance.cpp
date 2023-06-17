#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

// int dp[5000][5000];

// int f(string a,string b,int i,int j){
//     if(i<0)return j+1;
//     if(j<0)return i+1;
//     if(dp[i][j] != -1)return dp[i][j];
//     if(a[i] == b[j]){
//         return f(a,b,i-1,j-1);
//     }
//     int ans = 1 + f(a,b,i,j-1);
//     ans = min(ans,1+f(a,b,i-1,j));
//     ans = min(ans,1+f(a,b,i-1,j-1));
//     return dp[i][j] = ans;
// }

int main(){
    string a,b;cin >> a >> b;
    // memset(dp,-1,sizeof(dp));
    // cout << f(a,b,a.length()-1,b.length()-1) << endl;
    int n = a.length(), m = b.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)dp[i][0] = i;
    for(int i=0;i<=m;i++)dp[0][i] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            dp[i][j] = 1 + dp[i][j-1];
            dp[i][j] = min(dp[i][j],1+dp[i-1][j]);
            dp[i][j] = min(dp[i][j],1+dp[i-1][j-1]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}