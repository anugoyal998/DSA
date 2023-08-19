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
    int v[n+1];
    for(int i=1;i<=n;i++)cin >> v[i];
    int v1[n+1];
    v1[1] = v[1];
    for(int i=2;i<=n;i++){
        v1[i] = v[i] - v[i-1];
    }
    // for(int i=1;i<=n;i++)cout << v1[i] << " ";
    // cout << endl;
    for(int i=1;i<=n;i++)update(i,v1[i]);
    while(q--){
        int type;cin >> type;
        if(type == 1){
            int a,b,u;cin >> a >> b >> u;
            update(a,u);
            update(b+1,-u);
        }else{
            int k;cin >> k;
            cout << sum(k) << endl;
        }
    }
    return 0;
}