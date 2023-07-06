#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    // Give an array of coins. Alice and Bob are playing a game with Alice going first.
    // They've to choose any index 0<i<n and pick at least one coin from the index.
    // Winner of the game is the person who picks the last coin.
    // Determine winner of the game.

    // Solution:
    // NimSum = v[0] ^ v[1] ^ v[2] ... ^ v[n-2]  ^ v[n-1];  0 <= i < n
    // if(NimSum == 0) --> Bob
    // else --> Alice

    // xor = 0 ------------> non - zero xor value -------------------> min 1 move left  xor = 0                                 
    int n;cin >> n;vi v(n);
    for(auto &i:v)cin >> i;
    int ans = 0;
    for(auto i:v)ans ^= i;
    if(ans == 0)cout << "Bob\n";
    else cout << "Alice\n";
    return 0;
}