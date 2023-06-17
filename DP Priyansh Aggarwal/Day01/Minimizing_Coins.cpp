#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    int n,x;
    cin >> n >> x;
    vi v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    sort(v.begin(),v.end());
    int dp[x+1];
    dp[0] = 0;
    for(int i=1;i<v[0] and i<=x;i++)dp[i] = INT_MAX;
    for(int i=v[0];i<=x;i++){
        int mine = INT_MAX;
        for(int j=0;j<n;j++){
            int y = i - v[j];
            if(y < 0)break;
            if(dp[y] == INT_MAX)continue;
            mine = min(mine,dp[y]+1);
        }
        dp[i] = mine;
    }
    if(dp[x] == INT_MAX)cout << -1 << endl;
    else cout << dp[x] << endl;
    return 0;
}