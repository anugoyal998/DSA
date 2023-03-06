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
    for(int i = 0; i < n; i++)cin >> v[i];
    int ans = 1;
    int start = 0, end = 0;
    unordered_map<int,int> mp;
    while(end < n){
        int sz = mp.size();
        mp[v[end]]++;
        int size = mp.size();
        if(size == sz){
            while(start <= end and mp[v[end]] > 1){
                mp[v[start]]--;
                if(mp[v[start]] == 0)mp.erase(v[start]);
                size = mp.size();
                ans = max(ans,size);
                start++;
            }
        }else{
            ans = max(ans,size);
        }
        end++;
    }
    cout << ans << endl;
    return 0;
}