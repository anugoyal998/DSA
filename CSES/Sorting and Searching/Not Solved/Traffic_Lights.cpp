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
    int x,n;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    int ans = x;
    for(int i=0;i<n;i++){
        int light;
        cin >> light;
        s.insert(light);
        auto it = s.find(light);
        
    }
    return 0;
}