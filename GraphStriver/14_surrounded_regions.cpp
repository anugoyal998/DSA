//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

    typedef vector<int> vi;
    typedef vector<vi> vvi;

class Solution{
    int n,m;
    vector<vector<char>> g;
    vi dx = {-1,0,1,0}; // 4 directions
    vi dy = {0,1,0,-1}; // 4 directions
    // https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
public:
    vector<vector<char>> fill(int _n, int _m, vector<vector<char>> mat)
    {
        // code here
        n = _n, m = _m;
        g = mat;
        vvi vis(n,vi(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(g[i][0] == 'O' and !vis[i][0]){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(g[i][m-1] == 'O' and !vis[i][m-1]){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        for(int i=0;i<m;i++){
            if(g[0][i] == 'O' and !vis[0][i]){
                q.push({0,i});
                vis[0][i] = 1;
            }
            if(g[n-1][i] == 'O' and !vis[n-1][i]){
                q.push({n-1,i});
                vis[n-1][i] = 1;
            }
        }
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int _x = x + dx[i];
                int _y = y + dy[i];
                if(_x>=0 and _y>=0 and _x<n and _y<m and !vis[_x][_y] and g[_x][_y] == 'O'){
                    vis[_x][_y] = 1;
                    q.push({_x,_y});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 'O' and !vis[i][j])g[i][j] = 'X';
            }
        }
        return g;
    }
};

//{ Driver Code Starts.

int main(){
#ifndef ONLINE_JUDGE
freopen("error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends