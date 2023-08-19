#include <bits/stdc++.h>
using namespace std;
#define int long long

const int SIZE = 2*1e5;
int a[SIZE], seg[4*SIZE];

void build(int ind,int low,int high){
    if(low==high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low+high)>>1;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
}

void pointUpdate(int ind,int low,int high,int node,int val){
    if(low==high){
        seg[ind] = val;
    }else{
        int mid = (low+high)>>1;
        if(node>=low && node<=mid)pointUpdate(2*ind+1,low,mid,node,val);
        else pointUpdate(2*ind+2,mid+1,high,node,val);
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }
}

int query(int ind,int low,int high,int k){
    if(low==high)return low;
    else{
        int mid = (low+high)>>1;
        if(seg[2*ind+1]>=k)return query(2*ind+1,low,mid,k);
        else return query(2*ind+2,mid+1,high,k);
    }
}

int32_t main(){
    int n,m;cin >> n >> m;
    for(int i=0;i<n;i++)cin >> a[i];
    build(0,0,n-1);
    while(m--){
        int x;cin >> x;
        if(seg[0]<x){
            cout << 0 << "\n";
            continue;
        }
        int index = query(0,0,n-1,x);
        cout << index+1 << "\n";
        a[index] -= x;
        pointUpdate(0,0,n-1,index,a[index]);
    }
    return 0;
}