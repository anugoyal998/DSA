#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << "\n";
}

vector<int> segTree, lazy;

int merge(int a,int b){
    return min(a,b);
}

void propagate(int start,int end,int index){
    if(start == end){
        lazy[index] = -1;
        return;
    }
    lazy[2*index] += lazy[index];
    lazy[2*index+1] += lazy[index];
    lazy[index] = -1;
}

void build(vector<int>& arr,int start,int end,int index){
    // TC: O(N)
    // n + n/2 + n/4 + .... + 2 + 1 = 2n
    if(start == end){
        segTree[index] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    build(arr, start, mid, left);
    build(arr, mid+1, end, right);
    segTree[index] = merge(segTree[left],segTree[right]);
}

void update(int start,int end,int index,int l,int r,int value){
    // TC: O(logN)
    if(lazy[index] != -1){
        segTree[index] += lazy[index];
        propagate(start,end,index);
    }
    if(start>=l && end<=r){
        segTree[index] += value;
        lazy[index] += value;
        propagate(start,end,index);
        return;
    }
    if(start>r || end<l){
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    update(start,mid,left,l,r,value);
    update(mid+1,end,right,l,r,value);
    segTree[index] = merge(segTree[left],segTree[right]);
}

int query(int start,int end,int index,int l,int r){
    // TC: O(logN)
    // complete overlap
    // [l....start.....end.....r]
    if(lazy[index] != -1){
        segTree[index] += lazy[index];
        propagate(start,end,index);
    }
    if(start>=l && end<=r){
        return segTree[index];
    }
    // disjoint
    if(l>end || r<start){
        return INT_MAX;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    int leftAnswer = query(start,mid,left,l,r);
    int rightAnswer = query(mid+1,end,right,l,r);
    return merge(leftAnswer,rightAnswer);
}


void solve(){
    int n;cin >> n;
    segTree.resize(4*n,-1);
    lazy.resize(4*n,-1);
    vector<int> arr(n);
    for(auto &i:arr)cin >> i;
    build(arr,0,n-1,1);
    print(segTree);
    print(lazy);
    cout << query(0,n-1,1,0,2) << "\n";
    update(0,n-1,1,0,0,500);
    print(segTree);
    print(lazy);
    cout << query(0,n-1,1,0,2) << "\n";

    // update range by making all values = X
    // give range xor
}

int main(){
    solve();
    return 0;
}