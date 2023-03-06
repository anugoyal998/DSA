#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int n = 8;
vector<vector<char>> v(n,vector<char>(n));
// 0 --> free, 1 --> reserved

bool isSafe(int i,int j){
    if(v[i][j]=='*')return false;
    for(int k=0;k<n;k++){
        if(v[k][j] == 'Q')return false;
    }
    int row = i;
    int col = j;
    while(row>=0 and col>=0){
        if(v[row][col] == 'Q')return false;
        row--;col--;
    }
    row = i;
    col = j;
    while(row>=0 and col<n){
        if(v[row][col] == 'Q')return false;
        row--;col++;
    }
    return true;
}

int help(int i){
    if(i >= n)return 1;
    int ans = 0;
    for(int j=0;j<n;j++){
        if(isSafe(i,j)){
            v[i][j] = 'Q';
            ans += help(i+1);
            v[i][j] = '.';
        }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }

    cout << help(0) << endl;

    return 0;
}