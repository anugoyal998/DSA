#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

const int N = 1e6;
vector<ll> hashPrimes = {1000000009, 100000007};
const int base = 31;
const int primes = 2;
ll powersOfBase[2][N+1];
ll h1[2][N];
int n;

bool help(int mid){
    if(mid == 0)return true;
    int flag = 0;
    for(int j=0;j<primes;j++){
        ll val1 = h1[j][mid-1];
        ll val2 = 0LL;
        ll hash1 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
        hash1 = (hash1 * powersOfBase[j][n-mid]) % hashPrimes[j];
        val1 = h1[j][n-1];
        val2 = h1[j][n-1-mid];
        ll hash2 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
        if(hash1 == hash2)flag++;
    }
    if(flag != 2)return false;
    for(int i=1;i+mid-1<n-1;i++){
        flag = 0;
        for(int j=0;j<primes;j++){
            ll val1 = h1[j][mid-1];
            ll val2 = 0LL;
            ll hash1 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            hash1 = (hash1 * powersOfBase[j][i]) % hashPrimes[j];
            val1 = h1[j][i+mid-1];
            val2 = h1[j][i-1];
            ll hash2 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            if(hash1 == hash2)flag++;
        }
        if(flag == 2)return true;
    }
    return false;
}

int main(){
    string s;cin >> s;
    n = s.length();
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
    int ans = 0;
    for(int i=1;i<n;i++){
        if(help(i)){
            ans = i;
        }
    }
    if(ans == 0){
        cout << "Just a legend\n";
    }else{
        string ans1 = s.substr(0,ans);
        cout << ans1 << "\n";
    }
    return 0;
}