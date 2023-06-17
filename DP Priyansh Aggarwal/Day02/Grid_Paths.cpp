#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> v[i][j];
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    int x = 1;
    for(int i=0;i<n;i++){
        if(v[0][i] == '*')x = 0;
        dp[0][i] = x;
    }
    x = 1;
    for(int i=0;i<n;i++){
        if(v[i][0] == '*')x = 0;
        dp[i][0] = x;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(v[i][j] == '*')continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}