#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define mod 1000000007
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++)cin >> arr[i];
    ll sum = 0;
    int cnt = 0;
    int start = 0, end = 0;
    while(end < n){
        sum += arr[end];
        while(start <= end and sum >= x){
            if(sum == x)cnt++;
            sum -= arr[start++];
        }
        end++;
    }
    cout << cnt << endl;
    return 0;
}