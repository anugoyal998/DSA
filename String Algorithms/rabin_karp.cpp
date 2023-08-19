#include "bits/stdc++.h"
using namespace std;
#define ll long long

int p = 31;
const int N = 1e5+7, m = 1e9+7;
vector<ll> powers(N);

int main(){
	// https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1
	// find occurrences of s in t
	string s,t;
	cin >> s >> t;
	int T = t.length(), S = s.length();

	powers[0] = 1;
	for(int i=1;i<N;i++){
		powers[i] = (powers[i-1] * p) % m;
	}

	vector<ll> h(T+1,0);
	for(int i=0;i<T;i++){
		h[i+1] = (h[i] + (t[i] - 'a' + 1) * powers[i]) % m;
	}

	ll h_s = 0;
	for(int i=0;i<S;i++){
		h_s = (h_s + (s[i] - 'a' + 1) * powers[i]) % m;
	}

	for(int i=0;i + S - 1 < T;i++){
		ll cur_h = (h[i+S] - h[i] + m) % m;
		if(cur_h == (h_s * powers[i]) % m){
			cout << i << " ";
		}
	}


	return 0;
}