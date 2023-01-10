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

long long int fast_pow(int x,int y,long long int m/* modulo*/ = 1000000007){long long int res = 1;
    long int a = 1LL*x;
    long long int n = 1LL*y;

    while(n){
        if(n&1){
            res = (res * (a % m)) % m, n--;
        }
        a = ((a % m) * (a % m)) % m;
        n /= 2;
    }
    return res;
}

bool isPrime(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0)return false;
    }
    return true;
}

int gcd(int a,int b){
    return __gcd(a,b);
}

int lcm(int a,int b){
    return (a * b) / gcd(a,b);
}

class Solution {
    int n,m;
    vector<vector<char>> g;
    vvi vis;
    vi dx = {-1,-1,0,1,1,1,0,-1}; // 8 directions
    vi dy = {0,1,1,1,0,-1,-1,-1}; // 8 directions
    // vi dx = {-1,0,1,0}; // 4 directions
    // vi dy = {0,1,0,-1}; // 4 directions
    
    bool isSafe(int i,int j){
        if(i<0 or j<0 or i>=n or j>=m)return false;
        if(g[i][j] == '1' and vis[i][j] == 0)return true;
        return false;
    }
    
    void dfs(int i,int j){
        vis[i][j] = 1;
        for(int k=0;k<8;k++){
            int _i = i + dx[k];
            int _j = j + dy[k];
            if(isSafe(_i,_j)){
                dfs(_i,_j);
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        g = grid;
        n = g.size();
        m = g[0].size();
        int count = 0;
        vis = vvi(n,vi(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == '1' and vis[i][j] == 0){
                    dfs(i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

void solve(){
    // https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '#'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.numIslands(grid);
    cout << ans << '\n';
}

int main(){
#ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    // fastio();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}