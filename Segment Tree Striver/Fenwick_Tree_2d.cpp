#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

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
    
    return 0;
}