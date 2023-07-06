#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    // https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/game-theory/buddy--nim-official/ojquestion
    int n,m;cin >> n >> m;
    vi a(n), b(m);
    for(auto &i:a)cin >> i;
    for(auto &i:b)cin >> i;
    int sum1 = accumulate(a.begin(),a.end(),0);
    int sum2 = accumulate(b.begin(),b.end(),0);
    if(sum1 != sum2)cout << "ALICE\n";
    else{
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i = 0, j = 0;
        bool flag = true;
        while(i<n and a[i]==0)i++;
        while(j<m and b[j]==0)j++;
        while(i<n and j<m){
            if(a[i]!=b[j]){
                flag = false;break;
            }
            i++,j++;
        }
        if((!i==n and j==m))flag = false;
        if(flag)cout << "BOB\n";
        else cout << "ALICE\n";
    }
    return 0;
}