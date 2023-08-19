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
    string s;cin >> s;
    int n = s.length();
    ll powersOfBase[2][n+1];
    for(int j=0;j<primes;j++){
        powersOfBase[j][0] = 1;
        for(int i=1;i<=n;i++){
            powersOfBase[j][i] = (base * powersOfBase[j][i-1]) % hashPrimes[j];
        }
    }
    ll h1[2][n];
    for(int j=0;j<primes;j++){
        for(int i=0;i<n;i++){
            h1[j][i] = ((s[i]-'a'+1) * powersOfBase[j][i]) % hashPrimes[j];
            h1[j][i] = (h1[j][i] + (i > 0 ? h1[j][i-1] : 0LL)) % hashPrimes[j];
        }
    }
    vector<int> ans;
    for(int i=1;i<n;i++){
        int flag = 0;
        for(int j=0;j<primes;j++){
            ll val1 = h1[j][i-1];
            ll val2 = 0LL;
            ll hash1 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            hash1 = (hash1 * powersOfBase[j][n-i]) % hashPrimes[j];
            val1 = h1[j][n-1];
            val2 = h1[j][n-1-i];
            ll hash2 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            if(hash1 == hash2)flag++;
        }
        if(flag==2)ans.push_back(i);
    }
    for(auto i:ans)cout << i << " ";
    cout << endl;
    return 0;
}