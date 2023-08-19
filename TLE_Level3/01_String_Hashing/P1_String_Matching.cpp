#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

vector<ll> hashPrimes = {1000000009, 100000007};
const int base = 31;
const int primes = 2;

int main(){
    string txt,pat;cin >> txt >> pat;
    int n = txt.length(), m = pat.length();
    int len = max(n,m);
    ll powersOfBase[2][len+1];
    for(int j=0;j<primes;j++){
        powersOfBase[j][0] = 1;
        for(int i=1;i<=len;i++){
            powersOfBase[j][i] = (base * powersOfBase[j][i-1]) % hashPrimes[j];
        }
    }
    ll h1[2][n], h2[2][m];
    for(int j=0;j<primes;j++){
        for(int i=0;i<len;i++){
            if(i<n){
                h1[j][i] = ((txt[i]-'a'+1) * powersOfBase[j][i]) % hashPrimes[j];
                h1[j][i] = (h1[j][i] + (i > 0 ? h1[j][i-1] : 0LL)) % hashPrimes[j];
            }
            if(i<m){
                h2[j][i] = ((pat[i]-'a'+1) * powersOfBase[j][i]) % hashPrimes[j];
                h2[j][i] = (h2[j][i] + (i > 0 ? h2[j][i-1] : 0LL)) % hashPrimes[j];
            }
        }
    }
    // cout << h1[n-1] << " " << h2[m-1] << endl;
    int cnt = 0;
    for(int i=0;i+m-1<n;i++){
        int flag = 0;
        for(int j=0;j<primes;j++){
            ll val1 = h1[j][i+m-1];
            ll val2 = i > 0 ? h1[j][i-1] : 0LL;
            ll hash = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            ll expect_hash = (powersOfBase[j][i]*h2[j][m-1]) % hashPrimes[j];
            if(hash == expect_hash)flag++;
        }
        if(flag == primes){
            cnt++;
            // cout << i << " ";
        }
    }
    // cout << endl;
    cout << cnt << endl;
    return 0;
}