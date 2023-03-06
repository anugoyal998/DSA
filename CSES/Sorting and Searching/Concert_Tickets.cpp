#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin >> n >> m;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        if(s.empty()){
            cout << -1 << endl;
            continue;
        }
        auto it = s.lower_bound(x);
        if(it != s.end()){
            int val = *it;
            if(val == x){
                s.erase(it);
                cout << val << endl;
            }else if(it != s.begin()){
                it--;
                cout << *it << endl;
                s.erase(it);
            }else{
                cout << -1 << endl;
            }
        }else{
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }
    return 0;
}