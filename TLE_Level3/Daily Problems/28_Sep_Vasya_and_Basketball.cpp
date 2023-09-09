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

void solve(){
    int n;cin >> n;vi a(n);cin >> a;
    int m;cin >> m;vi b(m);cin >> b;
    sort(all(a));sort(all(b));
    int diff = 0;
    int x = -1, y = -1;
    for(int i=n-1;i>=0;i--){
        int d = a[i];
        int s1 = (i+1)*3 + (n-1-i)*2;
        int p = upper_bound(all(b),d) - b.begin();
        int s2 = 2*p + 3*(m-p);
        if(s1-s2>diff){
            diff = s1-s2;
            x = s1, y = s2;
        }else if(s1-s2==diff){
            if(s1>x)x = s1, y = s2;
        }

        d = a[i]-1;
        int p1 = upper_bound(all(a),d) - a.begin();
        s1 = 3*(n-p1) + 2*p1;
        int p2 = upper_bound(all(b),d) - b.begin();
        s2 = 3*(m-p2) + 2*p2;
        if(s1-s2>diff){
            diff = s1-s2;
            x = s1, y = s2;
        }else if(s1-s2==diff){
            if(s1>x)x = s1, y = s2;
        }
    }

    for(int i=0;i<m;i++){
        int d = b[i];
        int p1 = upper_bound(all(a),d) - a.begin();
        int s1 = 3*(n-p1) + 2*p1;
        int p2 = upper_bound(all(b),d) - b.begin();
        int s2 = 3*(m-p2) + 2*p2;
        if(s1-s2>diff){
            diff = s1-s2;
            x = s1, y = s2;
        }else if(s1-s2==diff){
            if(s1>x)x = s1, y = s2;
        }

        d = b[i]-1;
        p1 = upper_bound(all(a),d) - a.begin();
        s1 = 3*(n-p1) + 2*p1;
        p2 = upper_bound(all(b),d) - b.begin();
        s2 = 3*(m-p2) + 2*p2;
        if(s1-s2>diff){
            diff = s1-s2;
            x = s1, y = s2;
        }else if(s1-s2==diff){
            if(s1>x)x = s1, y = s2;
        }
    }
    cout << x << ":" << y << "\n";
}

int32_t main(){
    fastio();
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}