#include<bits/stdc++.h>
using namespace std;
#define ll long long


signed main()
{
	ll t;
	cin>>t;
	while(t--){
  ll n;
	cin>>n;
	vector<ll> a(n);
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll ans=0;
	sort(a.begin(),a.end());
	ans=(sum+1)/2;
	sum/=2;
	for(ll i=n-1;sum>0;i--){
		sum-=a[i];
		ans++;
	}
	cout<<ans<<endl;
   	}
  return 0;
}
