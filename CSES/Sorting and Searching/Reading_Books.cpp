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
    vi v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    sort(v.begin(), v.end());
    ll left = 0, right = 0;
    int start = 0, end = n-1;
    while(start <= end){
        if(left == right){
            left += v[start];
            right += v[end];
            start++,end--;
        }else if(left < right){
            left += v[start];
            start++;
        }else{
            right += v[end];
            end--;
        }
    }
    ll ans = 2*max(left, right);
    cout << ans << '\n';
    return 0;
}