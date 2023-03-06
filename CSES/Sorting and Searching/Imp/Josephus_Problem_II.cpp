#include <bits/stdc++.h>
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

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,k;
    cin >> n >> k;
    ordered_set<int> s;
    for(int i=0;i<n;i++)s.insert(i+1);
    int start = 0;
    while(s.size()){
        int size = s.size();
        int index = (start + k)%size;
        auto it = s.find_by_order(index);
        cout << *it << " ";
        s.erase(it);
        start = index;
    }
    return 0;
}