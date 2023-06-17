#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

class SegmentTreeLazy {
    vector<int> seg, lazy;
public:
    SegmentTreeLazy(int n,vector<int> arr){
        seg.resize(4*n+4);
        lazy.resize(4*n+4);
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
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
public:
    void update(int ind,int low,int high,int l,int r,int val){
        // update previous remaining updates
        // and propagate downwards
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];
            // propagate the lazy update downwards
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap
        if(high<l or r<low){
            return;
        }
        // complete overlap
        if(low>=l and high<=r){
            seg[ind] += (high - low + 1) * val;
            if(low != high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        // partial overlap
        int mid = low + (high - low) / 2;
        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+2,mid+1,high,l,r,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
public:
    int query(int ind,int low,int high,int l,int r){
        // updates if any update are remaining
        // and propagate downwards
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1) * lazy[ind];
            // propagate the lazy update downwards
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap
        if(high<l or r<low){
            return 0;
        }
        // complete overlap
        if(low>=l and high<=r){
            return seg[ind];
        }
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return left + right;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    SegmentTreeLazy st(n,arr);
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
            int l,r,val;
            cin >> l >> r >> val;
            st.update(0,0,n-1,l,r,val);
        }
    }
    return 0;
}