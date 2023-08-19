#include "bits/stdc++.h"
using namespace std;

vector<int> z_function_naive(string s){
    int n = s.length();
    vector<int> z(n,0);
    for(int i=1;i<n;i++){
        while(i+z[i] < n and s[z[i]] == s[i+z[i]])
            z[i]++;
    }
    return z;
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void print(vector<int> v){
    for(auto i:v)cout << i << " ";
    cout << endl;
}

int main(){

    // Z-function for string is an array of length n 
    // where ith element is equal to the greatest number of
    // characters starting from position i that coincide with
    // first characters of s.

    // z[i] = length of longest string i.e., at the same time,
    // a prefix of s and prefix of suffix of s starting at i.

    // z_function problem
    // https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb0f5/0000000000ba82c5

    string s;
    cin >> s;
    vector<int> z = z_function(s);
    print(z);
    return 0;
}