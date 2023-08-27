#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    int n;cin >> n;
    vector<int> v(n);
    for(auto &i:v)cin >> i;
    priority_queue<int> pq;
    for(int i=0; i<n; i++)pq.push(v[i]);

    pq.pop();
    pq.pop();

    cout << pq.top() << endl;
    return 0;
}