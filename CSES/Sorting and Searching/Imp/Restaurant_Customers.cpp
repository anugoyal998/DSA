#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n;
    cin >> n;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        s.insert(make_pair(x,1));
        s.insert(make_pair(y,-1));
    }
    int count = 0;
    int ans = 0;
    for(auto i:s){
        count += i.second;
        ans = max(ans,count);
    }
    cout << ans << endl;
    return 0;
}