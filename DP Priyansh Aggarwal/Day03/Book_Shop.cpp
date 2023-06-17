#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int f(vector<int> price,vector<int> page,int i,int x){
    if(i<0)return 0;
    int ans = 0;
    // take
    if(price[i] <= x)ans = max(ans, page[i] + f(price,page,i-1,x-price[i]));
    // not take
    ans = max(ans, f(price,page,i-1,x));
    return ans;
}

int main(){
    int n,x;cin >> n >> x;
    vi price(n);vi page(n);
    for(int i = 0; i <n;i++)cin >> price[i];
    for(int i = 0; i <n;i++)cin >> page[i];
    // cout << f(price,page,n-1,x) << endl;
    int dp[n+1][x+1];
    for(int i=0;i<=n;i++)dp[i][0] = 0;
    for(int i=0;i<=x;i++)dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            int op1 = (price[i-1] <= j) ? page[i-1] + dp[i-1][j-price[i-1]] : 0;
            int op2 = dp[i-1][j];
            dp[i][j] = max(op1,op2);
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}