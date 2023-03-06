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
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // https://cses.fi/problemset/task/1164
    // Room Allocation
    int n;
    cin >> n;
    vvi v;
    vvi rooms;
    for(int i=0;i<n;i++){
        int start,end;
        cin >> start;cin >> end;
        rooms.push_back({start,end,i});
        v.push_back({start,1,i});
        v.push_back({end,-1,i});
    }
    sort(v.begin(),v.end(),cmp);
    sort(rooms.begin(),rooms.end());
    vi ans(n);
    int cnt = 0;
    int maxe = 0;
    for(auto i:v){
        cnt += i[1];
        maxe = max(maxe,cnt);
        // if(i[1] == 1)ans[i[2]] = cnt;
    }
    ordered_set<pair<int,int>> s;
    map<pair<int,int>,int> m;
    ans[rooms[0][2]] = 1;
    s.insert({rooms[0][1],0});
    m[{rooms[0][1],0}] = 1;
    for(int i=1;i<n;i++){
        int x = s.order_of_key({rooms[i][0],-1*i});
        if(x == 0){
            m[{rooms[i][1],-1*i}] = m.size() + 1;
            ans[rooms[i][2]] = m.size();
            s.insert({rooms[i][1],-1*i});
        }else{
            auto it = s.begin();
            pair<int,int> p = *it;
            int pos = m[p];
            s.erase(it);
            m.erase(p);
            ans[rooms[i][2]] = pos;
            s.insert({rooms[i][1],-1*i});
            m[{rooms[i][1],-1*i}] = pos;
        }
    }
    cout << maxe << endl;
    print(ans);
    return 0;
}