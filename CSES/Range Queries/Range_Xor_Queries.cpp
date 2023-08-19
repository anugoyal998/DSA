#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;


const int SIZE = 2*1e5+1;
int a[SIZE], seg[4*SIZE];

void build(int ind,int low,int high){
    if(low==high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low+high)>>1;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = seg[2*ind+1]^seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r)return seg[ind];
    if(high<l || low>r)return 0;
    int mid = (low+high)>>1;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return left^right;
}

int main(){
    int n,q;cin >> n >> q;
    for(int i=0;i<n;i++)cin >> a[i];
    build(0,0,n-1);
    while(q--){
        int u,v;cin >> u >> v;u--,v--;
        cout << query(0,0,n-1,u,v) << endl;
    }
    return 0;
}