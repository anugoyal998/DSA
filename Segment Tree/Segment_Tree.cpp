#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5;
int a[SIZE], seg[4*SIZE];

void build(int ind,int low,int high){
    if(low==high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low+high)>>1;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r)return seg[ind];
    if(high<l || low>r)return 0;
    int mid = (low+high)>>1;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return left + right;
}

/* Increment the value at node by val*/
void pointUpdate(int ind,int low,int high,int node,int val){
    if(low==high){
        seg[ind] += val;
    }else{
        int mid = (low+high)>>1;
        if(node>=low && node<=mid)pointUpdate(2*ind+1,low,mid,node,val);
        else pointUpdate(2*ind+2,mid+1,high,node,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
}

int main(){
    int n;cin >> n;
    for(int i = 0; i < n;i++)cin >> a[i];
    build(0,0,n-1);
    int q;cin >> q;
    while(q--){
        int l,r;cin >> l >> r;
        cout << query(0,0,n-1,l,r) << endl;
    }

    return 0;
}