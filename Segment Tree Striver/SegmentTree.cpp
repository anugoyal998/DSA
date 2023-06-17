#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

class SegmentTree {
    int n;
    vector<int> seg;
public:
    SegmentTree(int n,vector<int> arr){
        this->n = n;
        seg.resize(4*n+4);
        build(0,0,n-1,arr);
    }
private:
    void build(int ind,int low,int high,vector<int> arr){
        if(low == high){
            seg[ind] = arr[low];
            return; 
        }
        int mid = low + (high - low) / 2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
public:
    int query(int ind,int low,int high,int l,int r){
        // no overlap
        if(r<low or high<l)return INT_MAX;
        // complete overlap
        if(low>=l and high<=r)return seg[ind];
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
public:
    void update(int ind,int low,int high,int index,int val){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(index<=mid) 
            update(2*ind+1,low,mid,index,val);
        else
            update(2*ind+2,mid+1,high,index,val);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    SegmentTree st(n,arr);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;    
        if(type == 1){
            int l,r;
            cin >> l >> r;
            cout << st.query(0,0,n-1,l,r) << endl;
        }else{
            int index,val;
            cin >> index >> val;
            st.update(0,0,n-1,index,val);
            arr[index] = val;
        }
    }
    return 0;
}