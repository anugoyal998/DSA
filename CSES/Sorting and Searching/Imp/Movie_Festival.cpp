#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first)return a.second < b.second;
    return a.first < b.first;
}

void print(vector<pair<int, int> > v){
    for(auto i:v)cout << i.first << " " << i.second << endl;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int ans = 1;
    int prev = v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first >= prev){
            ans++;
            prev = v[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}