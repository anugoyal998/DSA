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
    vi f(26,0);
    for(auto c:s)f[c-'A']++;
    int cnt = 0;
    for(auto i:f){
        if(i&1)cnt++;
    }
    if(cnt > 1)cout << "NO SOLUTION" << endl;
    else{
        string ans = "";
        int index = -1;
        for(int i=0;i<26;i++){
            if(f[i]&1){
                index = i;
                cnt = f[i];
            }else{
                f[i] /= 2;
                char ch = i + 'A';
                while(f[i]--)ans += ch;
            }
        }
        string ans2 = ans;
        reverse(ans2.begin(), ans2.end());
        while(index != -1 and cnt > 0){
            char ch = index + 'A';
            ans += ch;
            cnt--;
        }
        ans += ans2;
        cout << ans << endl;
    }
    return 0;
}