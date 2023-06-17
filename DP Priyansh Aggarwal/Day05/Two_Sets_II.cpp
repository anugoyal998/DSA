#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

const int mod = 1e9+7;

int32_t main(){
    int n;cin >> n;
    vi v(n);
    for(int i=0;i<n;i++)v[i] = i+1;
    int sum = (n*(n+1))/2;
    if(sum&1){
        cout << 0 << endl;return 0;
    }
    sum /= 2;
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)dp[0][i] = 0;
    for(int i=0;i<=n;i++)dp[i][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            int op1 = dp[i-1][j];
            int op2 = (v[i-1]<=j) ? dp[i-1][j-v[i-1]] : 0;
            dp[i][j] = (op1+op2)%mod;
        }
    }
    cout << (dp[n][sum]/2)<< endl;
    return 0;
}