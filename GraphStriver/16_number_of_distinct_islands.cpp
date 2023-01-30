//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


// User function Template for C++

class Solution {
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& arr,vector<pair<int,int>> &vec,int row0,int col0){
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        
        int n = arr.size();
        int m = arr[0].size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int i=0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and arr[nrow][ncol] == 1){
                dfs(nrow,ncol,vis,arr,vec,row0,col0);
            }
        }
    }
  public:
//   https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
    int countDistinctIslands(vector<vector<int>>& arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and arr[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,arr,vec,i,j);
                    s.insert(vec);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
freopen("error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends