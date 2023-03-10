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

vector<ll> dijkstra(ll n,vector<pair<ll,ll>> v[],ll src){
    vector<ll> distance(n+1,1e18);
    distance[src] = 0;
    set<pair<ll,ll>> s;
    s.insert({0,src});
    while(!s.empty()){
        auto it = s.begin();
        pair<ll,ll> p = *it;
        ll prevDistance = p.first;
        ll prevNode = p.second;
        s.erase(it);
        for(auto it:v[prevNode]){
            ll nextNode = it.first;
            ll nextDistance = prevDistance + it.second;
            if(nextDistance < distance[nextNode]){
                if(distance[nextNode] != 1e18)
                    s.erase({distance[nextNode],nextNode});
                distance[nextNode] = nextDistance;
                s.insert({nextDistance,nextNode});
            }
        }
    }
    for(auto &it:distance){
        if(it == 1e18)it = -1;
    }
    return distance;
}

void solve(){
    ll n,m,q;
    cin >> n >> m >> q;
    vector<pair<ll,ll>> v[n+1];
    vector<vector<ll>> distance;
    distance.pb({});
    loop(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    for(ll i=1;i<=n;i++){
        distance.pb(dijkstra(n,v,i));
    }
    for(ll i=1;i<=q;i++){
        ll a,b;
        cin >> a >> b;
        cout << distance[a][b] << endl;
    }
}

int main(){
#ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    fastio();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}