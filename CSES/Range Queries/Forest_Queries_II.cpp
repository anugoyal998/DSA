#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

int bit[N][N];

void update(int x,int y,int k){
    int __y = y;
    for(;x<N;x+= (x&-x)){
        for(y = __y;y<N;y+= (y&-y)){
            bit[x][y] += k;
        }
    }
}

int sum(int x,int y){
	int ans = 0;
    int __y = y;
    for(;x > 0; x-= (x&-x)){
        for(y = __y;y > 0; y-= (y&-y)){
            ans += bit[x][y];
        }
    }
	return ans;
}

int main(){
    int n,q;cin >> n >> q;
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;cin >> ch;
            if(ch == '*'){
                update(i+1,j+1,1);
                v[i][j] = 1;
            }
        }
    }
    while(q--){
        int type;cin >> type;
        if(type == 1){
            int x,y;cin >> x >> y;
            if(v[x-1][y-1]){
                update(x,y,-1);
                v[x-1][y-1] = 0;
            }else{
                update(x,y,1);
                v[x-1][y-1] = 1;
            }
        }else{
            int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            int ans = sum(x2,y2) - sum(x1-1,y2) - sum(x2,y1-1) + sum(x1-1,y1-1);
            cout << ans << "\n";
        }
    }
    return 0;
}