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

map<char,vi> m;

class Point{
    public:
    int l,r,d,u;
    Point(int _l,int _r,int _d,int _u){
        l = _l;r = _r;d = _d;u = _u;
    }
};

bool help(vector<Point> left,vector<Point> right,int x,int y,int mid){
    int n = left.size();
    int i = 0, j = mid-1;
    while(j<n){
        if(x >= 0){

        }else{
            
        }
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int start = 0, end = n;
    int ans = 0;
    vector<Point> left,right;
    int l = 0, r = 0, d = 0, u = 0;
    for(auto c:s){
        if(c == 'L')l++;
        if(c == 'R')r++;
        if(c == 'D')d++;
        if(c == 'U')u++;
        left.pb(Point(l,r,d,u));
    }
    l = 0, r = 0, d = 0, u = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == 'L')l++;
        if(s[i] == 'R')r++;
        if(s[i] == 'D')d++;
        if(s[i] == 'U')u++;
        right.pb(Point(l,r,d,u));
    }
    while(start <= end){
        int mid = (start + end)/2;
        if(help(left,right,x,y,mid)){
            ans = mid;
            end = mid-1;
        }else start = mid+1;
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