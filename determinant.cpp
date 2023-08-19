#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

vvi getCofactor(vvi arr,int x,int y){
    int n = arr.size();
    vvi v(n-1,vi(n-1));
    int vx = 0, vy = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == x or j == y)continue;
            v[vx][vy++] = arr[i][j];
            if(vy == n-1){
                vy = 0, vx++;
            }
        }
    }
    return v;
}

// 2 -1 -1
// -1 3 -1
// -1 -1 3

int getDeterminant(vvi arr){
    int n = arr.size();
    if(n==1)return arr[0][0];
    int ans = 0;
    int sign = 1;
    for(int i=0;i<n;i++){
        vvi cofactor = getCofactor(arr,0,i);
        ans += sign * arr[0][i] * getDeterminant(cofactor);
        sign *= -1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vvi arr(n,vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int determinant = getDeterminant(arr);
    cout << determinant << endl;
    return 0;
}