#include <bits/stdc++.h>
using namespace std;

// Segment Tree with point updates and range queries

template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<int> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<int> &a){ // change if type updated
        arr = a;
        n = a_len;  
        s = 1;
        // size of segment tree shoule be power of 2 and it should be at least 2n-1
        while(s < 2*n){
            s = s << 1;
        }
        tree.resize(s); fill(tree.begin(), tree.end(), Node());
        build(0, n-1, 1);
    }
    void build(int start,int end,int index){ // never change this
        if(start == end){
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = start + (end - start) / 2;
        build(start,mid,2*index);
        build(mid+1,end,2*index+1);
        tree[index].merge(tree[2*index],tree[2*index+1]);
    }
    void update(int start,int end,int index,int query_index,Update &u){ // never change this
        if(start == end){
            u.apply(tree[index]);
            return;
        }
        int mid = start + (end - start) / 2;
        if(mid >= query_index){
            update(start,mid,2*index,query_index,u);
        }else{
            update(mid+1,end,2*index+1,query_index,u);
        }
        tree[index].merge(tree[2*index],tree[2*index+1]);
    }
    Node query(int start,int end,int index,int left,int right){ // never change this
        if(start > right || end < left){
            return Node();
        }
        if(start >= left && end <= right){
            return tree[index];
        }
        int mid = start + (end - start) / 2;
        Node l,r,ans;
        l = query(start,mid,2*index,left,right);
        r = query(mid+1,end,2*index+1,left,right);
        ans.merge(l,r);
        return ans;
    }
    void make_update(int index,int val){ // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0,n-1,1,index,new_update);
    }
    Node make_query(int left,int right){
        return query(0,n-1,1,left,right);
    }
};

struct Node1 {
    int val; //  may change
    Node1(){ // Identity element
        val = 0; // may change
    }
    Node1(int p1){ // actual node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r){ // merge two child nodes
        val = l.val + r.val; // may change
    }
};

struct Update1 {
    int val; // may change
    Update1(int p1){ // Actual Update
        val = p1;
    }
    void apply(Node1 &a){ // apply update to given node
        a.val = val; // may change
    }
};

void solve(){   
    int n = 4;
    vector<int> arr = {1,2,3,4};
    SegTree<Node1, Update1> seg = SegTree<Node1,Update1>(n, arr);
    cout << seg.make_query(0,3).val << "\n";
    seg.make_update(2, 10);
    cout << seg.make_query(0,3).val << "\n";
}

int main(){
    solve();
    return 0;
}