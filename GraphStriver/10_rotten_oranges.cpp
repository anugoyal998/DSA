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

typedef pair<int,int> pi;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    vi dx = {-1,0,1,0}; // 4 directions
    vi dy = {0,1,0,-1}; // 4 directions
    int orangesRotting(vector<vector<int>>& g) {
        // Code here
        int n = g.size();
        int m = g[0].size();
        queue<pi> q;
        vvi vis(n,vi(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int timer = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pi p = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int x = p.first + dx[j], y = p.second + dy[j];
                    if(x>=0 and y>=0 and x<n and y<m and !vis[x][y] and g[x][y] == 1){
                        g[x][y] = 2;
                        q.push({x,y});
                        vis[x][y] = 1;
                    }
                }
            }
            timer++;
        }
        for(auto i:g){
            for(auto j:i){
                if(j == 1)return -1;
            }
        }
        return max(0,timer-1);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>grid(n, vector<int>(m, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";   
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
