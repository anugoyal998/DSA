#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << "\n";
}

void print(vector<int> v[],int n){
    for(int i=0;i<n;i++){
        print(v[i]);
    }
}

const int N = 800000;
int segTree[N][4];
 
void merge(vector<int> a,vector<int> b,int index){
    segTree[index][0] = a[0] + b[0];
    segTree[index][1] = max({a[1],a[0]+b[1]});
    segTree[index][2] = max({b[2],b[0]+a[2]});
    segTree[index][3] = max({a[3],b[3],a[0]+b[0],a[0]+b[1],b[0]+a[2],a[2]+b[1]});
}

vector<int> help(int index){
    vector<int> v(4);
    v[0] = segTree[index][0];
    v[1] = segTree[index][1];
    v[2] = segTree[index][2];
    v[3] = segTree[index][3];
    return v;
}
 
void build(vector<int>& arr,int start,int end,int index){
    // TC: O(N)
    // n + n/2 + n/4 + .... + 2 + 1 = 2n
    if(start == end){
        segTree[index][0] = arr[start];
        segTree[index][1] = arr[start];
        segTree[index][2] = arr[start];
        segTree[index][3] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    build(arr, start, mid, left);
    build(arr, mid+1, end, right);
    merge(help(left),help(right),index);
}
 
void update(vector<int>& arr,int start,int end,int index,int pos,int value){
    // TC: O(logN)
    if(start == end){
        arr[pos] = value;
        segTree[index][0] = arr[pos];
        segTree[index][1] = arr[pos];
        segTree[index][2] = arr[pos];
        segTree[index][3] = arr[pos];
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    if(pos <= mid){
        update(arr,start,mid,left,pos,value);
    }else{
        update(arr,mid+1,end,right,pos,value);
    }
    merge(help(left),help(right),index);
}
 
vector<int> query(int start,int end,int index,int l,int r){
    // TC: O(logN)
    // complete overlap
    // [l....start.....end.....r]
    vector<int> v = {0,0,0,0};
    if(start>=l && end<=r){
        return help(index);
    }
    // disjoint
    if(l>end || r<start){
        return v;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    vector<int> leftAnswer = query(start,mid,left,l,r);
    vector<int> rightAnswer = query(mid+1,end,right,l,r);
    merge(leftAnswer,rightAnswer,index);
    return help(index);
}
 
int32_t main(){
    int n,q;cin >> n >> q;
    vector<int> v(n);
    for(auto &i:v)cin >> i;
    memset(segTree,0,sizeof segTree);
    build(v,0,n-1,1);
    while(q--){
        int a, b;
        cin >> a >> b;
        update(v,0,n-1,1,a-1,b);
        cout << max(0LL, segTree[1][3]) << "\n";
    }
    return 0;
}