#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2*1e5+2;
int bit[N];

void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}


int32_t main(){
    int n,q;cin >> n >> q;
    int a[n+1];
    for(int i=1; i<=n;i++)cin >> a[i];
    for(int i=1; i<=n;i++)update(i,a[i]);
    while(q--){
        int type;cin >> type;
        if(type == 1){
            int k,u;cin >> k >> u;
            update(k,-a[k]);
            update(k,u);
            a[k] = u;
        }else{
            int u,v;cin >> u >> v;
            cout << sum(v) - sum(u-1) << endl;
        }
    }
    return 0;
}