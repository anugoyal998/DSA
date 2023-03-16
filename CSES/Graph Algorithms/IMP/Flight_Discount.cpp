#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline cout << endl;
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

typedef long long ll;
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

void _print(ll t) {cerr << t;}
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
void print(vvi v){for(auto i : v){print(i);}nline}

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================  

//  ======================================Graph Module========================================
vvi ipGraph(int n,int m,bool undirected = true){vvi v = vvi(n);loop(i,m){int x,y;cin >> x >> y;v[x].pb(y);if(undirected)v[y].pb(x);}return v;}
//  ======================================END OF Graph Module========================================


int n,m;

void dijkstra(vvi g[],ll distance[],int src){
    for(int i=1;i<=n;i++)distance[i] = INF;
    set<pair<ll,int>> s;
    s.insert({0,src});
    distance[src] = 0;
    while(s.size()){
        auto it = s.begin();
        pair<ll,int> p = *it;
        ll prevDistance = p.first;
        int prevNode = p.second;
        s.erase(it);
        for(auto iter:g[prevNode]){
            int nextNode = iter[0];
            ll nextDistance = prevDistance + iter[1];
            if(nextDistance < distance[nextNode]){
                if(distance[nextNode] != INF)
                    s.erase({distance[nextNode],nextNode});
                distance[nextNode] = nextDistance;
                s.insert({nextDistance,nextNode});
            }
        }
    }
}

vvi g1[100001];
vvi g2[100001];
ll distance1[100001];
ll distance2[100001];

void solve(){
    // Learning: by applying dijkstra we can find distance of every node from the src node
    // by reversing the same graph we can find the distance of src from every other node
    vvi edges;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g1[a].pb({b,c});
        g2[b].pb({a,c});
        edges.pb({a,b,c});
    }
    dijkstra(g1,distance1,1);
    dijkstra(g2,distance2,n);
    ll ans = INF;
    for(auto edge:edges){
        int a = edge[0], b = edge[1], c = edge[2];
        if(distance1[a] == INF or distance2[b] == INF)continue;
        ll d = distance1[a] + distance2[b] + c/2;
        ans = min(ans,d);
    }
    cout << ans << endl;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    // fastio();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}