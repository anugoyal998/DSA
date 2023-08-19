#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int n;cin >> n;
    int arr[n];
    ordered_set<int> s;
    for(int i=0; i<n;i++){
        s.insert(i);
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        int ind;cin >> ind;
        ind--;
        int pos = *s.find_by_order(ind);
        s.erase(pos);
        cout << arr[pos] << " ";
    }
    cout << endl;
    return 0;
}