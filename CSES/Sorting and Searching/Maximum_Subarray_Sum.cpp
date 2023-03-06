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
    ll sum = 0;
    ll ans = 0;
    int maxe = INT_MIN;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        maxe = max(maxe, x);
        sum += x;
        ans = max(ans, sum);
        if(sum < 0)sum = 0;
    }
    if(ans == 0){
        ans = maxe;
    }
    cout << ans << endl;
    return 0;
}