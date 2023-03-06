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
    ll x;
    cin >> n >> x;
    vector<pair<ll,int>> arr;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        arr.push_back({a,i+1});
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        int start = i+1, end = n-1;
        while(start < end){
            ll sum = arr[i].first + arr[start].first + arr[end].first;
            if(sum  == x){
                cout << arr[i].second << " " << arr[start].second << " " << arr[end].second;
                return 0;
            }
            if(sum < x)start++;
            else end--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}