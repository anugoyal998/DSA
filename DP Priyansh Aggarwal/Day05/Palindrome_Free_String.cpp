#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

bool notPalin(string a){
    string b = a;
    reverse(b.begin(), b.end());
    return a != b;
}

int f(string prev,int index,string s,vector<map<string,int>> &dp){
    if(index == s.length())return 1;
    if(dp[index].find(prev) != dp[index].end())return dp[index][prev];
    string x1 = prev.substr(1);
    string x2 = prev.substr(1);
    x1 += "0";
    x2 += "1";
    int ans = 0;
    if(s[index] == '?'){
        if(notPalin(x1) and notPalin(prev+"0")){
            ans += f(x1,index+1,s,dp);
        }
        if(notPalin(x2) and notPalin(prev+"1")){
            ans += f(x2,index+1,s,dp);
        }
    }else if(s[index] == '0'){
        if(notPalin(x1) and notPalin(prev+"0")){
            ans += f(x1,index+1,s,dp);
        }
    }else if(s[index] == '1'){
        if(notPalin(x2) and notPalin(prev+"1")){    
            ans += f(x2,index+1,s,dp);
        }
    }
    return dp[index][prev] = ans;
}

void solve(int i){
    int n;cin >> n;
    string s;cin >> s;
    vector<map<string,int>> dp(n);
    cout << "Case #" << i << ": ";
    if(f("?????",0,s,dp))cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}