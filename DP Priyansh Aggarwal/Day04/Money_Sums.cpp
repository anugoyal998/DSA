#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    int n;cin >> n;
    vector<int> v(n);
    for(auto &x:v)cin >> x;
    sort(v.begin(), v.end());
    int sum = 0;
    for(auto x:v)sum += x;
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;i++)dp[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(v[i-1] <= j){
                dp[i][j] = (dp[i-1][j] | dp[i-1][j-v[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> ans;
    for(int i=1;i<=sum;i++){
        if(dp[n][i])ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto x:ans)cout << x << " ";
    return 0;
}