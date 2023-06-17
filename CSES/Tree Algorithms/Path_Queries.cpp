#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

vvi adj;
vi in,out;
int timer = 0;

void dfs(int node,int par,vi &euler_tour,vi v){
    euler_tour.push_back(v[node]);
    in[node] = timer++;
    for(auto &child:adj[node]){
        if(child == par)continue;
        dfs(child,node,euler_tour,v);
    }
    euler_tour.push_back(-v[node]);
    out[node] = timer++;
}


struct seg_tree {
    vector<ll> seg;
    public:
    seg_tree (int n) {
        seg.resize(4*n + 1);
    }
    
    void build(int ind,int low,int high,vector<int>&euler_tour){
        if(low == high){
            seg[ind] = euler_tour[low]; return;
        }
 
        int mid = (low + high)/2;
        build(2*ind + 1,low,mid,euler_tour);
        build(2*ind + 2,mid + 1,high,euler_tour);
 
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
    #ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &x:v)cin >> x;
    adj.resize(n);
    in.resize(n,0);
    out.resize(n,0);
    for(int i = 0;i<n - 1;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> euler_tour;
    dfs(0,-1,euler_tour,v);
    int m = euler_tour.size();
    seg_tree s(m);
    s.build(0,0,m-1,euler_tour);

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int node,val; cin>>node>>val;
            node--;
            s.update(0,0,m-1,in[node],val);
            s.update(0,0,m-1,out[node],-val);
        }else{
            int node; cin>>node;
            node--;
            cout << s.query(0,0,m-1,0,in[node]) << endl;
        }
    }

    
    return 0;
}