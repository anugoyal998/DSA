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
    int n,k;cin >> n >> k;
    string s;cin >> s;
    for(int i=0;i<k;i++){
        if(s[i] == '?'){
            for(int j=i+k;j<n;j+=k){
                if(s[j] != '?'){
                    s[i] = s[j];break;
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        if(s[i] != '?'){
            for(int j=i+k;j<n;j+=k){
                if(s[j] == '?'){
                    s[j] = s[i];
                }else if(s[j] != s[i]){
                    cout << "NO\n";return;
                }
            }
        }
    }
    int one = 0, zero = 0;
    for(int i = 0; i <k;i++){
        if(s[i] == '1')one++;
        else if(s[i] == '0')zero++;
    }
    if(one<=(k/2) and zero<=(k/2)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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