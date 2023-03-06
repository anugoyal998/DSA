#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

void help(string s,int index,vector<string> &ans){
    if(index == s.length()){
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.length();i++){
        if(i != index and s[i] == s[index])continue;
        swap(s[index],s[i]);
        help(s,index+1,ans);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    help(s,0,ans);
    cout << ans.size() << endl;
    for(auto i:ans)cout << i << endl;
    return 0;
}