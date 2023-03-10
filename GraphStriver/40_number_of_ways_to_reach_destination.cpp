//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define vi vector<int>
#define vvi vector<vi>
#define ll long long

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int,int>>> v(n);
        for(auto i:roads){
            v[i[0]].push_back({i[1],i[2]});
            v[i[1]].push_back({i[0],i[2]});
        }
        ll mod = 1e9+7;
        vector<pair<ll,ll>> distance(n,{1e18,0});
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        pq.push({0,0});
        distance[0].first = 0;
        distance[0].second = 1;
        while(!pq.empty()){
            pair<ll,int> p = pq.top();
            pq.pop();
            ll prevDistance = p.first;
            int prevNode = p.second;
            ll prevSteps = distance[prevNode].second;
            for(auto it:v[prevNode]){
                int nextNode = it.first;
                ll nextDistance = prevDistance + it.second;
                if(nextDistance < distance[nextNode].first){
                    distance[nextNode].first = nextDistance;
                    distance[nextNode].second = prevSteps;
                    pq.push({distance[nextNode].first,nextNode});
                }else if(nextDistance == distance[nextNode].first){
                    distance[nextNode].second = (distance[nextNode].second + prevSteps) % mod;
                }
            }
        }
        return distance[n-1].second;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends