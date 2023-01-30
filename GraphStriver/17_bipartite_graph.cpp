#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool dfs(int src,vector<int> &vis,vector<int> adj[]){
     for(auto i:adj[src]){
          if(vis[i]==vis[src])return 1;
         if(vis[i]==-1){
              vis[i] = !vis[src];
              if(dfs(i,vis,adj))return 1;
         }
     }
     return 0;
    }  
public:
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> vis(n+1,-1);
	    for(int i=0;i<n;i++){
	        if(vis[i]==-1){
	            vis[i] = 1;
	            if(dfs(i,vis,adj)){
                    return 0;
               }
	        }
	    }
	    return 1;
	}

};

// { Driver Code Starts.
int main(){
    #ifndef ONLINE_JUDGE
freopen("error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends