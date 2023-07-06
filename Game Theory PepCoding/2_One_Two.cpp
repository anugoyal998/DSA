#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    // Given n coins, Alice and Bob playing a game with Alice going first. They can pick 1 or 2 coins.
    // The person picking the last coin will be the winner. Determine the winner of the game.
    int n;cin >> n;
    if(n%3 == 0)cout << "Bob\n";
    else cout << "Alice\n";
    return 0;
}