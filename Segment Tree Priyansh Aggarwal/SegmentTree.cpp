#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << "\n";
}

vector<int> segTree;
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
    segTree[index] = segTree[left] + segTree[right];
}

void update(vector<int>& arr,int start,int end,int index,int pos,int value){
    // TC: O(logN)
    if(start == end){
        arr[pos] = value;
        segTree[index] = arr[pos];
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    if(pos <= mid){
        update(arr,start,mid,left,pos,value);
    }else{
        update(arr,mid+1,end,right,pos,value);
    }
    segTree[index] = segTree[left] + segTree[right];
}

int query(int start,int end,int index,int l,int r){
    // TC: O(logN)
    // complete overlap
    // [l....start.....end.....r]
    if(start>=l && end<=r){
        return segTree[index];
    }
    // disjoint
    if(l>end || r<start){
        return 0;
    }
    int mid = start + (end - start) / 2;
    int left = 2*index, right = 2*index + 1;
    int leftAnswer = query(start,mid,left,l,r);
    int rightAnswer = query(mid+1,end,right,l,r);
    return leftAnswer + rightAnswer;
}

void solve(){
    int n;cin >> n;
    // for n beging power of 2 --> 2*n - 1
    // what if n is not a power of 2
    // [1,2,3,4,5] --> [1,2,3,4,5,0,0,0]
    // 5 nodes --> 8 nodes --> 2*8 - 1 = 17
    // if n is not a power of 2 --> convert array into the next power of 2
    // for any given N, next power of 2 for N will be <= 2*N
    // convert N to next power of 2 -> <= 2N --> 2 * (2N) - 1 <= 4N - 1
    segTree.resize(4*n);
    vector<int> arr(n);
    for(auto &i:arr)cin >> i;
    build(arr,0,n-1,1);
    print(segTree);
    cout << query(0,n-1,1,0,2) << "\n";
    update(arr,0,n-1,1,1,3);
    print(segTree);
    cout << query(0,n-1,1,0,2) << "\n";

    // update value at pos --> arr[pos] = value
    // give me second minimum in array
    // left --> min1, second min1
    // right --> min2, second min2
    // if(min1 < min2)
        // current.min = min1
        // current.second_min = min(min2,second_min1)
    // else
        // current.min = min2
        // current.second_min = min(min1,second_min2)
}

int main(){
    solve();
    return 0;
}