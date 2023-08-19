#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;


const int SIZE = 2*1e5+1;
int a[SIZE], seg[4*SIZE];

void print(int n,int v[]){
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

void build(int ind,int low,int high){
    if(low==high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low+high)>>1;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r)return seg[ind];
    if(high<l || low>r)return INT_MAX;
    int mid = (low+high)>>1;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return min(left,right);
}

void pointUpdate(int ind,int low,int high,int node,int val){
    if(low==high){
        seg[ind] = val;
    }else{
        int mid = (low+high)>>1;
        if(node>=low && node<=mid)pointUpdate(2*ind+1,low,mid,node,val);
        else pointUpdate(2*ind+2,mid+1,high,node,val);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
}


int main(){
    int n,q;cin >> n >> q;
    for(int i=0;i<n;i++)cin >> a[i];
    build(0,0,n-1);
    while(q--){
        int type;cin >> type;
        if(type == 1){
            int k,u;cin >> k >> u;k--;
            pointUpdate(0,0,n-1,k,u);
            a[k] = u;
        }else{
            int u,v;cin >> u >> v;u--,v--;
            cout << query(0,0,n-1,u,v) << endl;
        }
    }
    return 0;
}