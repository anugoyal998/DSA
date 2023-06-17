#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

const int N = 1e6+1;
int dp[N];

int f(int n){
    if(n == 0)return 0;
    if(dp[n] != -1)return dp[n];
    string s = to_string(n);
    int ans = INT_MAX;
    for(auto c:s){
        int x = c-'0';
        if(x == 0)continue;
        ans = min(ans,1 + f(n-x));
    }
    return dp[n] = ans;
}

int main(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=9;i++)dp[i] = 1;
    for(int i=10;i<=n;i++){
        int x = i;
        string s = to_string(x);
        int ans = INT_MAX;
        for(auto c:s){
            int y = c-'0';
            if(y == 0)continue;
            ans = min(ans,1+dp[x-y]);
        }
        dp[x] = ans;
    }
    cout << dp[n] << endl;
    return 0;
}