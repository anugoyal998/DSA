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
    string s;
    cin >> s;
    int n = s.length();
    int ans = 1;
    int i = 1;
    while(i<n){
        int cnt = 1;
        while(i<n and s[i] == s[i-1]){
            cnt++;
            i++;
        }
        ans = max(ans, cnt);
        i = i + (cnt == 1 ? 1 : 0);
    }
    cout << ans << endl;
    return 0;
}