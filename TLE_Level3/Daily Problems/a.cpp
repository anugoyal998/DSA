#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

void solve(){
    string s;cin >> s;int k;cin >> k;
    int n = s.length();

    if(k == 0){
        cout << s << endl;return;
    }
    int mine = 10;
    int index = -1;
    for(int i=0;i<=k;i++){
        if(s[i] == '0')continue;
        int x = s[i] - '0';
        if(x<mine){
            mine = x;
            index = i;
        }
    }

    // cout << mine << " " << index << endl;

    // 987654321

    k -= index;

    // 66837494128
    vi vis(n,0);

    for(int i = 0; i <index;i++)vis[i] = 1;

    vector<pair<int,int>> v;
    for(int i=index+1;i<n;i++){
        v.push_back({s[i]-'0',i});
    }

    sort(v.begin(),v.end());
    // reverse(v.begin(),v.end());

    // 66837494128

    int ind = index;


    for(int i=0;i<v.size() && k>0;i++){
        if(v[i].second-index-1>k)continue;
        k -= v[i].second - index - 1;
        for(int j=index+1;j<v[i].second;j++)vis[j] = 1;
        index = v[i].second;
    }

    v.clear();

    for(int i=0;i<n;i++){
        if(!vis[i] and i!=ind)
            v.push_back({s[i]-'0',i});
    }

    // cout << k << endl;

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    for(int i=0;i<v.size() && k>0;i++){
        vis[v[i].second] = 1;
        k--;
    }

    // cout << k << endl;

    string ans = "";

    for(int i=0;i<n;i++){
        if(!vis[i])ans += s[i];
    }

    cout << ans << endl;
    
}

int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}