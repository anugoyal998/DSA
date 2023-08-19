#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    int n;cin >> n; string s;cin >> s;
    s = "#" + s  + "#";
    int ans = 0, f = 0;
    while(s.size() > 2){    
        f= 0 ;
        for(int i=1;i<=n;i++){
            if(s[i]-s[i-1]==1 || s[i]-s[i+1]==1){
                if(f==0 || s[f]<s[i]){
                    f = i;
                }
            }
        }
        if(f==0)break;
        s.erase(f,1);
        ans++;
    }
    cout << ans << endl;
    return 0;
}