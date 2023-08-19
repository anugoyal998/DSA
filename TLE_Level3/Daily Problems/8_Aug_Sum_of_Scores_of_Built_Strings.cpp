#define ll long long

vector<ll> hashPrimes = {1000000009, 100000007};
const int base = 31;
const int primes = 2;

class Solution {
public:
    long long sumScores(string s) {
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
        ll cnt = 0;
        for(int i=1;i<=n;i++){
            int low = 0, high = i;
            int ans = 0;
            while(low<=high){
                int mid = (low+high)/2;
                int flag = (mid == 0 ? 2 : 0);
                for(int j=0;j<primes && mid != 0;j++){
                    ll val1 = h1[j][mid-1];
                    ll val2 = 0LL;
                    ll hash1 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
                    hash1 = (hash1 * powersOfBase[j][n-i]) % hashPrimes[j];
                    val1 = h1[j][n-i+mid-1];
                    val2 = i != n ? h1[j][n-i-1] : 0LL;
                    ll hash2 = (val1 - val2 + hashPrimes[j]) % hashPrimes[j];
                    if(hash1 == hash2)flag++;
                }
                if(flag==2){
                    ans = mid;
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            // cout << ans << " ";
            cnt += ans;
        }
        return cnt;
    }
};