#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

int main(){
    int n;cin >> n;vi arr(n);
    for(auto &x:arr)cin >> x;
    vector<int> ans = {arr[0]};
    for(int i=1;i<n;i++){
        if(arr[i] > ans[ans.size()-1])ans.push_back(arr[i]);
        else{
            int idx = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
    }
    cout << ans.size() << endl;  
    return 0;
}