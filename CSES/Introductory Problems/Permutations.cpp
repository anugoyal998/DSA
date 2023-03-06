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
    if(n == 2 or n == 3){
        cout << "NO SOLUTION";
        return 0;
    }
    for(int i=2;i<=n;i+=2){
        cout << i << " ";
    }
    for(int i=1;i<=n;i+=2){
        cout << i << " ";
    }
    return 0;
}