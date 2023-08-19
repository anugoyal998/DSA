#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5;
int a[SIZE], seg[4*SIZE], lazy[4*SIZE];

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

int queryLazy(int ind,int low,int high,int l,int r,int val){
    if(lazy[ind]!=0){
        seg[ind] += (high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(r<low || l>high || low>high)return 0;

    if(low>=l && high<=r)return seg[ind];

    int mid = (low+high)>>1;
    int left = queryLazy(2*ind+1,low,mid,l,r,val);
    int right = queryLazy(2*ind+2,mid+1,high,l,r,val);
    return left + right;
}

void rangeUpdate(int ind,int low,int high,int l,int r,int val){
    if(lazy[ind]!=0){
        seg[ind] += (high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(r<low || l>high || low>high)return;

    if(low>=l && high<=r){
        seg[ind] += (high-low+1)*val;
        if(low!=high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        return;
    }

    int mid = (low+high)>>1;
    rangeUpdate(2*ind+1,low,mid,l,r,val);
    rangeUpdate(2*ind+2,mid+1,high,l,r,val);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int main(){
    
    return 0;
}