#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

vector<vector<int>> segTree;

vector<int> merge(vector<int> a,vector<int> b,int start,int end){
    int op1 = a[0], op2 = b[0], op3 = a[1] + b[1], op4 = a[0] + b[0];
    int maxe = max({op1,op2,op3});
    if(b[2]-a[3] == 1){
        maxe = max(maxe,op4);
    }
    if(maxe == op1)return {maxe,op3,a[2],a[3]};
    if(maxe == op2)return {maxe,op3,b[2],b[3]};
    if(maxe == op3)return {maxe,op3,start,end};
    return {maxe,op3,a[2],b[3]};
}

void build(vector<int>& arr,int start,int end,int index){
    // TC: O(N)
    // n + n/2 + n/4 + .... + 2 + 1 = 2n
    if(start == end){
        segTree[index] = {arr[start],arr[start],start,start};
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
        segTree[index] = {arr[pos],arr[pos],start,start};
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

vector<int> query(int start,int end,int index,int l,int r){
    // TC: O(logN)
    // complete overlap
    // [l....start.....end.....r]
    if(start>=l && end<=r){
        return segTree[index];
    }
    // disjoint
    if(l>end || r<start){
        return {0,0,-2,-2};
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    vector<int> leftAnswer = query(start,mid,left,l,r);
    vector<int> rightAnswer = query(mid+1,end,right,l,r);
    return merge(leftAnswer,rightAnswer,start,end);
}

int main(){
    int n,q;cin >> n >> q;
    vector<int> v(n);
    for(auto &i:v)cin >> i;
    segTree.resize(4*n,vector<int>(4));
    build(v,0,n-1,1);
    while(q--){
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1){
            update(v,0,n-1,1,a-1,b);
        }else{
            cout << query(0,n-1,1,a-1,b-1)[0] << "\n";
        }
    }
    return 0;
}