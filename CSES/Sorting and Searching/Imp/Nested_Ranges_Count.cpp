#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

bool cmp(vi a,vi b){
    if(a[0] != b[0])return a[0] < b[0];
    return a[1] > b[1];
}

void print(vi v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vvi v(n,vi(3));
    for(int i=0;i<n;i++){
        cin >> v[i][0];
        cin >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(),v.end(),cmp);
    ordered_set<pair<int,int>> s;
    vi contains(n,0);
    for(int i=n-1;i>=0;i--){
        s.insert({v[i][1],-1*i});
        contains[v[i][2]] = s.order_of_key({v[i][1],-1*i});
    }
    s.clear();
    vi contained(n,0);
    for(int i=0;i<n;i++){
        s.insert({v[i][1],-1*i});
        contained[v[i][2]] = s.size() - s.order_of_key({v[i][1],-1*i}) - 1;
    }
    print(contains);
    print(contained);
    return 0;
}