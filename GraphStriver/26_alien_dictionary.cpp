//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    // https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<pair<char,char>> edges;
        for(int i=0;i<n-1;i++){
            string a = dict[i];
            string b = dict[i+1];
            for(int i=0;i<min(a.length(),b.length());i++){
                if(a[i] != b[i]){
                    edges.push_back({a[i],b[i]});break;
                }
            }
        }
        
        unordered_map<char,vector<char>> arr;
        unordered_map<char,int> in;
        for(int i=0;i<k;i++)
            in[i + 'a'] = 0;
        for(auto i:edges){
            arr[i.first].push_back(i.second);
            in[i.second]++;
        }
        
        queue<char> q;
        for(auto i:in){
            if(i.second == 0)q.push(i.first);
        }
        
        string ans = "";
        while(q.size()){
            char ch = q.front();
            q.pop();
            ans += ch;
            for(auto i:arr[ch]){
                in[i]--;
                if(in[i] == 0)q.push(i);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    #ifndef ONLINE_JUDGE
freopen("error.txt","w",stderr);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends