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
#define loop1(start,i,end) for(int i=start; i<end; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef vector<vector<long long>> vvl;

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
void print(vd v){for(auto i : v){cout << i << " ";}nline}
void print(vl v){for(auto i : v){cout << i << " ";}nline}
void print(vvi v){for(auto i : v){print(i);}nline}
void print(vvd v){for(auto i : v){print(i);}nline}
void print(vvl v){for(auto i : v){print(i);}nline}

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


void solve(){
    int n,m;
    cin >> n >> m;
    vvi g[n];
    ll distance[n];
    loop(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        g[a].pb({b,c});
    }
    loop(i,n){
        distance[i] = 1e18;
    }
    vector<int> parent[n];
    distance[0] = 0;
    set<pair<ll,int>> s;
    s.insert({0,0});
    while(!s.empty()){
        auto it = s.begin();
        auto p = *it;
        ll a = p.first;
        int b = p.second;
        s.erase(it);
        for(auto iter:g[b]){
            int c = iter[0], d = iter[1];
            ll nextDistance = a + d;
            if(nextDistance < distance[c]){
                distance[c] = nextDistance;
                parent[c].clear();
                parent[c].pb(b);
                s.insert({nextDistance,c});
            }else if(nextDistance == distance[c]){
                parent[c].pb(b);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     print(parent[i]);
    // }
    vi v[n];
    vi deg(n,0);
    loop(i,n){
        for(auto j:parent[i]){
            v[i].pb(j);
            deg[j]++;
        }
    }
    vector<ll> cnt(n,0);
    vi mine(n,1e8);
    vi maxe(n,0);
    queue<int> q;
    for(int i=0;i<n-1;i++){
        if(deg[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:v[node]){
            deg[it]--;
            if(deg[it] == 0 and it != n-1)
                q.push(it);
        }
    }
    q.push(n-1);
    cnt[n-1] = 1;
    mine[n-1] = 0;
    maxe[n-1] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it:v[node]){
            deg[it]--;
            cnt[it] = (cnt[it] + cnt[node]) % MOD;
            mine[it] = min(mine[it],1 + mine[node]);
            maxe[it] = max(maxe[it],1 + maxe[node]);
            if(deg[it] == 0)
                q.push(it);
        }
    }
    cout << distance[n-1] <<  " ";
    cout << cnt[0] <<  " ";
    cout << mine[0] <<  " ";
    cout << maxe[0] <<  " ";
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