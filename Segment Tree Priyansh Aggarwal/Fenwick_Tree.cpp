#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int bit[N];

void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}

// galat h yeh code
// struct FenwickTree {
//     int n;
//     vector<int> bit;

//     FenwickTree(vector<int> a) {
//         n = a.size();
//         bit.resize(n+1,0);
//         for(int i = 0; i<n;i++)upd(i,a[i]);
//     }
    
//     void upd(int i,int x){
//         for(i++;i<=n;i+=i&-i)bit[x] += x;
//     }

//     int sum(int i){
//         int s = 0;
//         for(i++;i>0;i -= i&-i)s += bit[i];
//         return s;
//     }

//     int query(int l,int r){
//         return sum(r) - sum(l-1);
//     }
// };

// yeh bhi glt h pr isme query wala dekh lena bss
struct FenwickTree2D {
    int n,m;
    vector<vector<int>> bit;

    FenwickTree2D(vector<vector<int>> &a){
        n = a.size();
        m = a[0].size();
        bit.resize(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                upd(i,j,a[i][j]);
            }
        }
    }

    void upd(int r,int c,int x){
        for(int i=r+1;i<=n;i+=i&-i){
            for(int j=c+1;j<=m;j+=j&-j){
                bit[i][j] += x;
            }
        }
    }

    int sum(int r,int c){
        int s = 0;
        for(int i=r+1;i>0;i -= i&-i){
            for(int j=c+1;j>0;j -= j&-j){
                s += bit[i][j];
            }
        }
        return s;
    }

    int query(int r1,int c1,int r2,int c2){
        return sum(r2,c2) - sum(r1-1,c2) - sum(r2,c1-1) + sum(r1-1,c1-1);
    }
};

void solve(){
    // bit[i] = sum(a[f(i) + 1,i])
    // f(i) = i with last set bit cleared
    // f(5) = 100 or 4
    // 1 2 3 4
    update(1,1);
    update(2,2);
    update(3,3);
    update(4,4);
    cout << sum(3) << "\n";
    update(2,3);
    cout << sum(3) << "\n";
}

int main(){
    solve();
    return 0;
}