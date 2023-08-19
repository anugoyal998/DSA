#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6;
vector<ll> hashPrimes = {1000000007};
const int base = 29;
const int primes = 1;
ll powersOfBase[primes][N+1];
ll h1[primes][N];
int n;

bool help(int mid){
    // cout << "mid: " << mid << endl;
    for(int i=mid;i+mid-1<n;i+=mid){
        int flag = 0;
        // a a a a
        for(int j=0;j<primes;j++){
            ll val1 = h1[j][mid-1];
            ll val2 = 0LL;
            ll hash1 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            hash1 = (hash1 * powersOfBase[j][i]) % hashPrimes[j];
            val1 = h1[j][i+mid-1];
            val2 = (i > 0 ? h1[j][i-1] : 0LL);
            ll hash2 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
            // cout << hash1 <<  " "   << hash2 << endl;
            if(hash1 == hash2) flag++;
        }
        // cout << i << " " << flag << endl;
        if(flag != primes)return false;
    }
    if(n%mid == 0)return true;
    int start = (n/mid)*mid, end = n-1;
    int rem = n%mid;
    int flag = 0;
    for(int j=0;j<primes;j++){
        ll val1 = h1[j][rem-1];
        ll val2 = 0LL;
        ll hash1 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
        hash1 = (hash1 * powersOfBase[j][start]) % hashPrimes[j];
        val1 = h1[j][end];
        val2 = (start > 0 ? h1[j][start-1] : 0LL);
        ll hash2 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
        if(hash1 == hash2) flag++;
    }
    return flag == primes;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // aaaa
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

    // for(int j=0;j<primes;j++){
    //     for(int i=0;i<n;i++){
    //         cout << h1[j][i] <<  " ";
    //     }
    // }

    // 1 30 871 25260

    // cout << endl;


    vector<int> ans(n+1,0);
    ans[n] = 1;
    // help(1);
    for(int i=1;i<n;i++){
        if(ans[i] == 1)continue;
        if(help(i)){
            int x = i;
            while(x<n){
                ans[x] = 1;
                x += i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i])cout << i << " ";
    }

    return 0;
}
