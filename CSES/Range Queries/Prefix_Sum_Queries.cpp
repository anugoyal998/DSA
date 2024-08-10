#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 800000;

pair<int,int> segTree[N];

pair<int,int> merge(pair<int,int> a,pair<int,int> b,int start,int end){
    int op1 = a.first, op2 = a.second + b.first;
    int maxe = max({op1,op2});
    return {maxe,a.second + b.second};
}

void build(vector<int>& arr,int start,int end,int index){
    // TC: O(N)
    // n + n/2 + n/4 + .... + 2 + 1 = 2n
    if(start == end){
        segTree[index].first = arr[start];
        segTree[index].second = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    build(arr, start, mid, left);
    build(arr, mid+1, end, right);
    segTree[index] = merge(segTree[left],segTree[right],start,end);
}

void update(vector<int>& arr,int start,int end,int index,int pos,int value){
    // TC: O(logN)
    if(start == end){
        arr[pos] = value;
        segTree[index].first = arr[pos];
        segTree[index].second = arr[pos];
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    if(pos <= mid){
        update(arr,start,mid,left,pos,value);
    }else{
        update(arr,mid+1,end,right,pos,value);
    }
    segTree[index] = merge(segTree[left],segTree[right],start,end);
}

pair<int,int> query(int start,int end,int index,int l,int r){
    // TC: O(logN)
    // complete overlap
    // [l....start.....end.....r]
    if(start>=l && end<=r){
        return segTree[index];
    }
    // disjoint
    if(l>end || r<start){
        return {0,0};
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    pair<int,int> leftAnswer = query(start,mid,left,l,r);
    pair<int,int> rightAnswer = query(mid+1,end,right,l,r);
    return merge(leftAnswer,rightAnswer,start,end);
}

int32_t main(){
    int n,q;cin >> n >> q;
    vector<int> v(n);
    for(auto &i:v)cin >> i;
    build(v,0,n-1,1);
    while(q--){
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1){
            update(v,0,n-1,1,a-1,b);
        }else{
            cout << max(0LL, query(0,n-1,1,a-1,b-1).first) << "\n";
        }
    }
    return 0;
}