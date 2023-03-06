#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

bool cmp(vi a,vi b){
    if(a[0] != b[0])return a[0] < b[0];
    return a[1] > b[1];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vvi v(n,vi(2));
    for(int i=0;i<n;i++){
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(), v.end(),cmp);
    // sort(v.begin(), v.end());
    ll ans = 0;
    ll start = 0;
    for(auto i:v){
        ans += i[1] - i[0] - start;
        start += i[0];
    }
    cout << ans << endl;
    return 0;
}