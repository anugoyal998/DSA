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
    int diff = -1*1e12;
    int s1 = -1, s2 = -1;

    for(int _x=0;_x<=n;_x++){
        int d;
        int x,y;
        if(_x == 0){
            d = a[0] - 1;
            x = _x;
        }else{
            d = a[_x-1];
            x = lower_bound(all(a),d+1) - a.begin();
        }
        y = lower_bound(all(b),d+1) - b.begin();
        int _diff = 3*(n-m) - x + y;
        // cout << x << " " << y << " " << _diff << endl;
         if(_diff > diff){
            diff = _diff;
            s1 = 2*x + 3*(n-x);
            s2 = 2*y + 3*(m-y);
        }else if(_diff == diff){
            if(2*x + 3*(n-x) > s1){
                s1 = 2*x + 3*(n-x);
                s2 = 2*y + 3*(m-y);
            }
        }
    }

    // cout << endl;
    // cout << endl;

    for(int _y=0;_y<=m;_y++){
        int d;
        int x,y;
        if(_y == 0){
            d = b[0] - 1;
            y = _y;
        }else{
            d = b[_y-1];
            y = lower_bound(all(b),d+1) - b.begin();
        }
        x = lower_bound(all(a),d+1) - a.begin();
        int _diff = 3*(n-m) - x + y;
        // cout << x << " " << y << " " << _diff << endl;
         if(_diff > diff){
            diff = _diff;
            s1 = 2*x + 3*(n-x);
            s2 = 2*y + 3*(m-y);
        }else if(_diff == diff){
            if(2*x + 3*(n-x) > s1){
                s1 = 2*x + 3*(n-x);
                s2 = 2*y + 3*(m-y);
            }
        }
    }

    // cout << diff << endl;
    cout << s1 << ":" << s2 << endl;
}

int32_t main(){
// #ifndef ONLINE_JUDGE
// freopen("Error.txt","w",stderr);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
    fastio();
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}