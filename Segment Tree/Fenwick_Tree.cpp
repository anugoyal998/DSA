#include<bits/stdc++.h>
using namespace std;


/* To get the range --> turn off the rightmost set bit and add 1 to it this will give L*/
/* R = current index*/
const int N = 1e5+10;
int bit[N];

void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}

int findLowerBoundWithPrefixSum(int k){
    int curr = 0, ans = 0, prevSum = 0;
    for(int i=log2(N);i>=0;i--){
        if(bit[curr+(1<<i)]+prevSum<k){
            curr = curr + (1<<i);
            prevSum += bit[curr];
        }
    }
    return curr+1;
}

int main(){
	
}