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
    cout << 0 << endl;
    ll sum = 0;
    for(int i=2,j=0;i<=n;i++,j++){
        sum += j;
        ll i_2 = i*i;
        ll ans = (i_2*(i_2-1))/2;
        ans = ans - 8*sum;
        cout << ans << endl;
    }
    return 0;
}