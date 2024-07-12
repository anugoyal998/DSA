#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline cout << "\n";
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i,n) for(int i=0; i<n; i++)
#define loop1(start,i,end) for(int i=start; i<end; i++)

typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ";_print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void print(vi v){for(auto i : v){cout << i << " ";}nline}
void print(vd v){for(auto i : v){cout << i << " ";}nline}
void print(vvi v){for(auto i : v){print(i);}nline}
void print(vvd v){for(auto i : v){print(i);}nline}

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================  

void modadd(int &a , int b,int m=MOD) {a=((a%m)+(b%m))%m;}
void modsub(int &a , int b,int m=MOD) {a=((a%m)-(b%m)+m)%m;}
void modmul(int &a , int b,int m=MOD) {a=((a%m)*(b%m))%m;}

vector<int> parent;
vector<int> wt;
vector<int> ssize;
vector<int> weight;

int findUPar(int node) {
    if(node == parent[node])
        return node; 
    return parent[node] = findUPar(parent[node]); 
}

void uunion(int u,int v, int &maxe){
    int ulp_u = findUPar(u); 
    int ulp_v = findUPar(v); 
    if(ulp_u == ulp_v) return;
    if(ssize[ulp_u] < ssize[ulp_v]){
        parent[ulp_u] = ulp_v; 
        ssize[ulp_v] += ssize[ulp_u];  
        wt[ulp_v] += wt[ulp_u];
        maxe = max(maxe,wt[ulp_v]);
    }else{
        parent[ulp_v] = ulp_u;
        ssize[ulp_u] += ssize[ulp_v]; 
        wt[ulp_u] += wt[ulp_v];
        maxe = max(maxe,wt[ulp_u]);
    }
}

void solve(){
    int n;cin >> n;
    weight.clear();
    weight = vector<int>(n);
    cin >> weight;
    vvi edges;
    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        u--,v--;
        edges.push_back({weight[u] + weight[v], u, v});
    }
    sort(all(edges));
    reverse(all(edges));
    vi pre(n-1);
    pre[0] = edges[0][0];
    for(int i=1;i<n-1;i++)pre[i] = pre[i-1] + edges[i][0];
    vector<int> ans(n-1);
    ans[0] = accumulate(all(weight),0LL);
    ans[n-2] = pre[n-2];
    parent.clear();
    ssize.clear();
    parent = vector<int>(n);
    ssize = vector<int>(n);
    wt = vector<int>(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
        wt[i] = weight[i];
    }
    int sum = 0;
    uunion(edges[n-2][1],edges[n-2][2],sum);
    debug(sum);
    debug(parent);
    for(int i=n-3;i>=1;i--){
        uunion(edges[i][1],edges[i][2],sum);
        debug(sum);
        debug(parent);
        // if(!vis[edges[i][1]]){
        //     vis[edges[i][1]] = 1;
        //     sum += weight[edges[i][1]];
        // }
        // if(!vis[edges[i][2]]){
        //     vis[edges[i][2]] = 1;
        //     sum += weight[edges[i][2]];
        // }
        ans[i] = sum + pre[i-1];
    }
    cout << ans << "\n";
}

int32_t main(){
#ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    fastio();
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}