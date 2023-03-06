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
    ll t;
    cin >> t;
    while(t--){
        ll x,y;
        cin >> x >> y;
        if(x%2 == 0){
            if(y <= x){
                ll r = x*x;
                cout << r - y + 1 << endl;
            }else{
                if(y%2 == 1){
                    ll r = y*y;
                    cout << r - x + 1 << endl;
                }else{
                    ll r = y*y;
                    cout << r + x << endl;
                }
            }
        }else{
            if(y <= x){
                ll r = x*x;
                cout << r - 2*x + y + 1 << endl;
            }else{
                if(y%2 == 0){
                    ll r = y*y;
                    cout << r - y << endl;
                }else{
                    ll r = y*y;
                    cout << r - x + 1 << endl;
                }
            }
        }
    }
    return 0;
}