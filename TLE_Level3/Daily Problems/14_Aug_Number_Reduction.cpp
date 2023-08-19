#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

const int N = 500010;
int bit[N];

void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}

void solve(){
    string s;cin >> s;int k;cin >> k;
    int n = s.length();
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({s[i]-'0',i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    for(auto i:v){
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;

    for(int i=0;i<=n;i++)cout << bit[i] << " ";
    cout << endl;

    // 7808652
    vector<int> vis(n,0);
    for(int i=0;i<n && k>0;i++){
        cout << sum(v[i].second+1) << endl;
        if(i!=n-1 and s[v[i].second+1] == '0' and !vis[v[i].second+1]){
            if(sum(v[i].second+1) == v[i].second+1)continue;
        }
        k--;
        vis[v[i].second] = 1;
        update(v[i].second+1,1);
    }
    string ans = "";
    for(int i = 0; i <n;i++){
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