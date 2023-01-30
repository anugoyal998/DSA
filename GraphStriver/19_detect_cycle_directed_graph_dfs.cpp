#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define vi vector<int>
class Solution
{
    
    public:
    bool dfs(int src,vi adj[],vi &vis,vi &dfs_vis){
    vis[src] = 1;
    dfs_vis[src] = 1;
    for(auto i:adj[src]){
        if(vis[i]==1 and dfs_vis[i]==1)return 1;
        if(vis[i]==0 and dfs(i,adj,vis,dfs_vis))return 1;
    }
    dfs_vis[src] = 0;
    return  0;
    }  
	//Function to detect cycle in a directed graph.
    // https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
	bool isCyclic(int n, vector<int> adj[]) 
	{
	   	// code here
	   	 vi vis(n,0);
         vi dfs_vis(n,0);
         for(int i=0;i<n;i++){
            if(dfs(i,adj,vis,dfs_vis)){
                return 1;
            }
         }
         return 0;
	}
};

// { Driver Code Starts.


int main()
{
    #ifndef ONLINE_JUDGE
freopen("error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends