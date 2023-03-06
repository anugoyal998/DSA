#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int n;
int ans = 0;
vector<pair<int, int>> v;
void tower(int n,int src,int help,int dest){
    if(n==0)return;
    tower(n-1,src,dest,help);
    ans++;
    v.push_back({src,dest});
    tower(n-1,help,src,dest);
} 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    tower(n,1,2,3);
    cout << ans << endl;
    for(auto i:v)cout << i.first << " " << i.second << endl;
    return 0;
}