
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

unordered_map<char,char> parent;
unordered_map<char,char> parent1;
unordered_map<char,bool> vis;
unordered_map<char,int> _rank;

char findPar(char node){
    if(node == parent[node])return node;
    return findPar(parent[node]);
}

void uunion(char a,char b){
    char u = findPar(a);
    char v = findPar(b);
    if(u == v)return;
    if(_rank[u] < _rank[v]) {
        parent[u] = v; 
    }
    else if(_rank[v] < _rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[u] = v; 
        _rank[v]++; 
    }
}

char update(char c){
    if(c == 'z')return 'a';
    return ++c;
}

void print(unordered_map<char,char> m){
    cout << m['a'] << " " << m['b'] << " " << m['z'] << endl;
}

void solve(){
    // https://codeforces.com/problemset/problem/1735/C
    int n;
    cin >> n;
    string s;
    cin >> s;
    loop(i,26){
        char ch = i + 'a';
        parent[ch] = ch;
        parent1[ch] = ch;
        vis[ch] = false;
        _rank[ch] = 0;
    }

    string ans = "";
    char ch = 'a';
    for(auto c:s){
        if(vis[c]){
            ans += parent1[c];
            continue;
        }
        char par = findPar(c);
        if(par == ch){
            ch = update(ch);
            parent[ch] = c;
            parent1[c] = ch;
            vis[c] = true;
            ch = update(ch);
            ans += parent1[c];
            print(parent);
            print(parent1);
            nline;
            continue;
        }
        parent[ch] = c;
        parent1[c] = ch;
        vis[c] = true;
        ch = update(ch);
        ans += parent1[c];
        print(parent);
        print(parent1);
        nline;
    }
    cout << ans << endl;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    fastio();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}