#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;

vi tree[200001];
int depth[200001];
int ans[200001];

void eval_depth(int src,int par){
    int src_depth = 0;
    for(auto child:tree[src]){
        if(child != par){
            eval_depth(child, src);
            src_depth = max(src_depth,1+depth[child]);
        }
    }
    depth[src] = src_depth;
}

void solve(int src,int par,int par_ans){
    vi prefixMax, suffixMax;
    for(auto child:tree[src]){
        if(child != par){
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }
    
    for(int i=1;i<prefixMax.size();i++)
        prefixMax[i] = max(prefixMax[i],prefixMax[i-1]);
    for(int i=suffixMax.size()-2;i>=0;i--)
        suffixMax[i] = max(suffixMax[i],suffixMax[i+1]);

    int c_no = 0;
    for(auto child:tree[src]){
        if(child != par){
            int op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no-1];
            int op2 = (c_no == suffixMax.size()-1) ? INT_MIN : suffixMax[c_no+1];
            int partial_ans = 1 + max(par_ans,max(op1,op2));
            solve(child,src,partial_ans);
            c_no++;
        }
    }
    ans[src] = 1 + max(par_ans,(prefixMax.empty() ? -1 : prefixMax.back()));
}

int main(){

    return 0;
}