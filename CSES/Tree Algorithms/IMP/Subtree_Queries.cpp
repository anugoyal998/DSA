#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
 
vvi adj;
vi vis,siz;
int timer = 0;
 
void dfs(int node,int par,vi &euler,vi &pos){
    euler.push_back(node);
    pos[node] = timer++;
    siz[node] = 1;
    for(auto &child:adj[node]){
        if(child == par)continue;
        dfs(child,node,euler,pos);
        siz[node] += siz[child];
    }
}
 
struct seg_tree {
    vector<ll> seg;
    public:
    seg_tree (int n) {
        seg.resize(4*n + 1);
    }
    
    void build(int ind,int low,int high,vector<int>&euler_tour,vector<int>&v){
        if(low == high){
            seg[ind] = v[euler_tour[low]]; return;
        }
 
        int mid = (low + high)/2;
        build(2*ind + 1,low,mid,euler_tour,v);
        build(2*ind + 2,mid + 1,high,euler_tour,v);
 
        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }
 
    void update(int ind,int low,int high,int i,int val){
        if(low == high){
            seg[ind] = val; return;
        }
 
        int mid = (low + high)/2;
 
        if(i <= mid)update(2*ind + 1,low,mid,i,val);
        else update(2*ind + 2,mid + 1,high,i,val);
 
        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }
    
    ll query (int ind,int low,int high,int l,int r) {
        if(r < low || high < l)return 0;
 
        if(low >= l && high <= r)return seg[ind];
 
        int mid = (low + high)/2;
 
        ll left = query(2*ind + 1,low,mid,l,r);
        ll right = query(2*ind + 2,mid + 1,high,l,r);
 
        return left + right;
    }
};
 
 
int main(){
    int n,q;cin >> n >> q;
    vector<int>v(n);
    for(auto &x : v)cin>>x;    
 
    adj.resize(n);
    siz.resize(n,0);
    // for(int i = 0;i<n;i++)adj[i].clear();
    
    for(int i = 0;i<n - 1;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    vector<int>euler_tour,pos(n);
    dfs(0,-1,euler_tour,pos);
    seg_tree s1(n);
    s1.build(0,0,n-1,euler_tour,v);
    // for(int i = 0;i<n;i++)pos[euler_tour[i]] = i;
 
    while(q--){
        int type; cin>>type;
        if(type == 1){
            int node,val; cin>>node>>val;
            node--;
            int p = pos[node];
            s1.update(0,0,n-1,p,val);
        }else{
            int node; cin>>node;
            node--;
            int len = siz[node];
            int p = pos[node];
            ll ans = s1.query(0,0,n-1,p,len + p - 1);
            cout<<ans<<"\n";
        }
    }
 
    return 0;
}