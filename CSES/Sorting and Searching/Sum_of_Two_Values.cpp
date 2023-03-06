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
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back({a,i+1});
    }
    sort(v.begin(), v.end());
    int i = 0, j = n-1;
    while(i<j){
        int sum = v[i].first + v[j].first;
        if(sum == x){
            cout << v[i].second << " " << v[j].second << endl;
            return 0;
        }
        if(sum > x)j--;
        else i++;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}