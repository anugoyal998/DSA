#include "bits/stdc++.h"
using namespace std;

vector<int> manachers_algorithm_naive(string s){
    int n = s.length();
    s = "$" + s + "^";
    vector<int> p(n+2,0);
    for(int i=1;i<=n;i++){
        while(s[i-p[i]] == s[i+p[i]])
            p[i]++;
    }
    return vector<int>(begin(p)+1,end(p)-1);
}

vector<int> manachers_algorithm_odd(string s){
    // maximum odd length palindrome centered at i
    // here d1[i] = the palindrome has d1[i]-1 right characters
    // from i e.g. for aba d1[1] = 2;

    int n = s.length();
    vector<int> d1(n);
    for(int i=0,l=0,r=-1;i<n;i++){
        int k = (i>r) ? 1 : min(d1[l+r-i],r-i);
        while(0 <= i-k and i+k < n and s[i-k] == s[i+k])
            k++;
        d1[i] = k--;
        if(i+k > r){
            l = i-k;
            r = i+k;
        }
    }
    return d1;
}

vector<int> manachers_algorithm_even(string s){
    // maximum even Length palindrome centered at i
    // here d2[i] = the palindrome has d2[i]-1 right characters
    // from i e.g. for abba, d2[2] = 2; 

    int n = s.length();
    vector<int> d2(n);
    for(int i=0,l=0,r=-1;i<n;i++){
        int k = (i>r) ? 0 : min(d2[l+r-i+1],r-i+1);
        while(0 <= i-k-1 and i+k<n and s[i-k-1] == s[i+k])
            k++;
        d2[i] = k--;
        if(i+k > r){
            l = i-k-1;
            r = i+k;
        }
    }
    return d2;
}

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){
    string s;
    cin >> s;

    vector<int> p = manachers_algorithm_naive(s);
    vector<int> odd = manachers_algorithm_odd(s);
    vector<int> even = manachers_algorithm_even(s);
    print(odd);
    print(even);

    return 0;
}