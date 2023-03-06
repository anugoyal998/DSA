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
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans ^= i;
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    return 0;
}