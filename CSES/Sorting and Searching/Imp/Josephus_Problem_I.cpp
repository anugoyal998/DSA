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
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++)v[i] = i + 1;
    while(v.size() > 1) {
        vi x;
        for(int i=0;i<v.size();i++){
            if(i%2 == 1){
                cout << v[i] << " ";
            }else{
                x.push_back(v[i]);
            }
        }
        if(v.size()%2 == 0){
            v = x;
        }else{
            int y = x.back();
            x.pop_back();
            v.clear();
            v.push_back(y);
            for(auto i:x){
                v.push_back(i);
            }
        }
    }
    cout << v[0] << endl;
    return 0;
}