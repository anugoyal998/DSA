#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back({x,i});
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    int index = v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].second < index){
            cnt++;
        }
        index = v[i].second;
    }
    cout << cnt << endl;
    return 0;
}