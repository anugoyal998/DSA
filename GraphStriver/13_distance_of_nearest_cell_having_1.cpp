//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

class Solution 
{
    vi dx = {-1,0,1,0}; // 4 directions
    vi dy = {0,1,0,-1}; // 4 directions
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    // https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1
	vector<vector<int>>nearest(vector<vector<int>> g)
	{
	    int n = g.size(), m = g[0].size();
	    vvi vis(n,vi(m,0));
	    vvi ans(n,vi(m,INT_MAX));
	    queue<vi> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(g[i][j] == 1){
	                vis[i][j] = 1;
	                ans[i][j] = 0;
	                q.push({i,j,0});
	            }
	        }
	    }
	    while(q.size()){
	        vi v = q.front();
	        q.pop();
	        int i = v[0], j = v[1], timer = v[2];
	        for(int k=0;k<4;k++){
	            int x = i + dx[k];
	            int y = j + dy[k];
	            if(x>=0 and y>=0 and x<n and y<m and !vis[x][y]){
	                ans[x][y] = timer+1;
	                vis[x][y] = 1;
	                q.push({x,y,timer+1});
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
#ifndef ONLINE_JUDGE
freopen("error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends