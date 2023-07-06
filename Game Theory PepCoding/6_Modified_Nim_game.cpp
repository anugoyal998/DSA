#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    // https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/game-theory/a-modified-game-of-nim-official/ojquestion
    int n;cin >> n;vi v(n);
    for(auto &i:v)cin >> i;
    int common = 0, three = 0, five = 0;
    for(auto i:v){
        if(i%15 == 0){
            common++;continue;
        }
        if(i%3 == 0)three++;
        if(i%5 == 0)five++;
    }
    if(common != 0)three++;
    if(three > five)cout << "Alice\n";
    else cout << "Bob\n";
    return 0;
}