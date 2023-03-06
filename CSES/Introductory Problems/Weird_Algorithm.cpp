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
    ll n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n%2 == 0)  n /= 2;
        else n = 3*n + 1;
    }   
    cout << 1 << endl;
    return 0;
}