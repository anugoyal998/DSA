#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    // https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/game-theory/first-move-in-a-nim-game-official/ojquestion
    int n;cin >> n;vi v(n);
    for(auto &i:v)cin >> i;
    int xxor = 0;
    for(auto i:v)xxor ^= i;
    if(xxor == 0){
        cout << -1 << endl;
    }else{
        int ans = 0;
        for(auto i:v){
            int x = xxor ^ i;
            if(x<i)ans++;
        }
        cout << ans << endl;
    }
    return 0;
}