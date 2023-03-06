#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int n = 2;

vvi vis(n,vi(n,0));

vi dx = {-1,0,1,0}; // 4 directions
vi dy = {0,1,0,-1}; // 4 directions

bool isSafe(int i,int j){
    if(i >= 0 and j >= 0 and i < n and j < n)return true;
    return false;
}


void help(int i,int j,int n,int &count){
    if(i == n and j == 0){
        count++;
        return;
    }
    vis[i][j] = 1;
    for(int k=0;k<4;k++){
        int _i = i + dx[k];
        int _j = j + dy[k];
        if(isSafe(_i, _j) and !vis[_i][_j]){
            help(_i, _j, n,count);
        }
    }
    vis[i][j] = 0;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int count = 0;
    help(0,0,n,count);
    cout << count << endl;
    
    return 0;
}