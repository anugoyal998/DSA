#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

bool cmp(vi a,vi b){
    if(a[0] != b[0])return a[0] < b[0];
    return a[1] > b[1];
}


struct Treap{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

    Treap(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(long long x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(long long x){
        x += MAXVAL;
        int c = mp[x];
        if (c){
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k){
        if (k < 1 || k > len) return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }

    /// Count of value < x in treap
    inline int count(long long x){
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }

    /// Number of elements in treap
    inline int size(){
        return len;
    }
};

void solve(){
    int n;cin >> n;vvi v(n,vi(2));
    for(int i=0;i<n;i++){
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(),v.end(),cmp);
    ll ans = 0;
    Treap t;
    int i = 0;
    int broken = 0;
    while(i<n){
        ans += v[i][1];
        // cout << ans << endl;
        int lamps = t.size() + 1 - broken;
        t.insert(v[i][0]);
        i++;
        while(i<n and v[i][0] <= lamps)t.insert(v[i][0]),i++;
        broken = t.count(lamps+1);
    }
    cout << ans << "\n";
}

int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}