#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    // https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/game-theory/winner-in-nim-game-official/ojquestion
    int n;cin >> n; vi v(n);
    for(auto &i:v)cin >> i;
    int xxor = 0;
    for(auto i:v)xxor ^= i;
    if(xxor == 0)cout << "Alice\n";
    else{
        if(n%2 == 0)cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}