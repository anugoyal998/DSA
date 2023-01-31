//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(int node,vector<int> adj[],int vis[],int pathVis[],int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto it:adj[node]){ 
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,check)){
                    check[node] = 0;
                    return true;
                }
            }else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
  public:
//   https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathVis,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i] == 1)safeNodes.push_back(i);
        }
        return safeNodes;
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends