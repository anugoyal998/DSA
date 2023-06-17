#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int f(int i,const vvi& v,int tight,map<pair<int,int>,int> &dp){
    if(i >= v.size())return 0;
    if(dp.find({i,tight}) != dp.end())return dp[{i,tight}];
    if(v[i][0] <= tight)return dp[{i,tight}] = f(i+1,v,tight,dp);
    int take = v[i][2] + f(i+1,v,v[i][1],dp);
    int notTake = f(i+1,v,tight,dp);
    return dp[{i,tight}] = max(take,notTake);
}

int32_t main(){
    int n;cin >> n;
    vvi v;
    for(int i=0; i<n;i++){
        int a,b,c;cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end());
    int dp[n-1];
    dp[n-1] = v[n-1][2];
    for(int i=n-2;i>=0;i--){
        int start = i+1, end = n-1;
        int pos = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(v[mid][0] > v[i][1]){
                pos = mid;
                end = mid-1;
            }else start = mid+1;
        }
        int take;
        if(pos == -1){
            take = v[i][2];
        }else{
            take = v[i][2] + dp[pos];
        }
        int notTake = dp[i+1];
        dp[i] = max(take, notTake);
    }
    cout << dp[0] << endl;
    return 0;
}