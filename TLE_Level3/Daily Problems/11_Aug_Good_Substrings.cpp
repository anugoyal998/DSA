#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}


const int N = 1500;
vector<ll> hashPrimes = {100000007};
const int base = 31;
const int primes = 1;
ll powersOfBase[primes][N+1];
ll h1[primes][N];
int n;
int k;

int getCnt(int c,int l,int r,vvi cnt){
    if(l == 0)return cnt[c][r];
    return (cnt[c][r]-cnt[c][l-1]);
}

bool ok(int i,int j,string x,vvi cnt){
    int total = 0;
    for(int c=0;c<26;c++){
        total += (x[c] == '0') * getCnt(c,i,j,cnt);
    }
    return total <= k;
}

int main(){
    string s;cin >> s;
    string x;cin >> x;
    cin >> k;
    n = s.length();
    vvi cnt(26,vi(n,0));
    for(int i=0;i<n;i++){
        cnt[s[i]-'a'][i] = 1;
    }
    for(int c=0;c<26;c++){
        for(int i=1;i<n;i++){
            cnt[c][i] += cnt[c][i-1];
        }
    }

    for(int j=0;j<primes;j++){
        powersOfBase[j][0] = 1;
        for(int i=1;i<=n;i++){
            powersOfBase[j][i] = (base * powersOfBase[j][i-1]) % hashPrimes[j];
        }
    }
    for(int j=0;j<primes;j++){
        for(int i=0;i<n;i++){
            h1[j][i] = ((s[i]-'a'+1) * powersOfBase[j][i]) % hashPrimes[j];
            h1[j][i] = (h1[j][i] + (i > 0 ? h1[j][i-1] : 0LL)) % hashPrimes[j];
        }
    }
    map<ll,int> m;
    for(int i=0;i<n;i++){
        ll p;
        ll inv_p;
        for(int j=0;j<primes;j++){
            ll val1 = h1[j][i];
            ll val2 = i > 0 ? h1[j][i-1] : 0LL;
            ll hash = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            ll inv = mminvprime(powersOfBase[j][i], hashPrimes[j]);
            inv_p = inv;
            p = hash;
        }
        if(ok(i,i,x,cnt)){
            ll q = (p*inv_p) % hashPrimes[0];
            m[q] = 1;
        }
        for(int j=i+1;j<n;j++){
            ll q;
            for(int k=0;k<primes;k++){
                ll hash = ((s[j]-'a'+1) * powersOfBase[k][j]) % hashPrimes[k];
                hash = (hash + p) % hashPrimes[k];
                q = (hash * inv_p) % hashPrimes[k];
            }
            if(ok(i,j,x,cnt))m[q] = 1;
        }
    }
    cout << m.size() << endl;
    return 0;
}