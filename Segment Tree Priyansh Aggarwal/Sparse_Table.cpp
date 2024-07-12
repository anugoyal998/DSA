#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

int table[MAX_N][25];
int log[MAX_N];

void build_log(int N){
    log[1] = 0;
    for(int i=2;i<=N;i++){
        log[i] = 1 + log[i/2];
    }
}

void build(vector<int> dataVector){
    int N = dataVector.size();
    for(int L=N-1; L>=0; L--){
        for(int W = 0; W<25; W++){
            int R = L + (1<<W);
            if(R>=N)break;
            if(W == 0)table[L][W] = dataVector[L];
            else table[L][W] = min(table[L][W-1], table[L + (1<<(W-1))][W-1]);
        }
    }
}

int query(int L,int R){
    int W = R - L;
    int power = low[W];
    return min(table[L][1<<power], table[R - (1<<power)][1<<power]);
}

int main(){
    // Sparse Table
    // find range min in O(1) with no updates
    // What's a Sparse Table?
    // 1. table[i]][j] --> answer to query [i, i + 2^j - 1]
    // How can it answer Queries?
    // 1. Range Sum Queries?
        // --> [L, R] is the range [L, L + W] where W = R - L
        // --> W can be written as a binary number. For ex. if W = 45 then W = (101101) in binary.
    // 2. Any range of size W can be broken down into <= logW ranges.
    // 3. For above example we can answer as follows:
        // --> sum(L, R) = table[L][5] + table[L1][3] + table[L2][2] + table[L3][0]
    return 0;
}