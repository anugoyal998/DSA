#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

const int N = 200000;
vi g[N];
int in[N], out[N], v[N];
int euler_tour[2*N];
ll seg[8*N+1];
int timer = 0;

void build(int ind,int low,int high){
    if(low == high){
        seg[ind] = euler_tour[low]; return;
    }

    int mid = (low + high)/2;
    build(2*ind + 1,low,mid);
    build(2*ind + 2,mid + 1,high);

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

void dfs(int node,int par){
    euler_tour[timer] = v[node];
    in[node] = timer++;
    for(auto &child:g[node]){
        if(child == par)continue;
        dfs(child,node);
    }
    euler_tour[timer] = v[node];
    out[node] = timer++;
}

int main(){
    #ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)cin >> v[i];
    for(int i = 0;i<n - 1;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0,-1);
    int m = 2*n;
    build(0,0,m-1);
    while(q--){
        int type; cin>>type;
        if(type == 1){
            int node,val; cin>>node>>val;
            node--;
            update(0,0,m-1,in[node],val);
            update(0,0,m-1,out[node],-val);
        }else{
            int node; cin>>node;
            node--;
            cout << query(0,0,m-1,0,in[node]) << endl;
        }
    }
    return 0;
}