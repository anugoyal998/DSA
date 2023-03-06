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
    vector<string> arr;
    arr.push_back("0");
    arr.push_back("1");
    int i,j;
    for(i=2;i<(1<<n);i = i<<1){
        for (j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);
        // append 0 to the first half
        for (j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];
        // append 1 to the second half
        for (j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }
    for(auto s:arr)
        cout << s << endl;
    return 0;
}