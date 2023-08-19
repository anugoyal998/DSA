#include "bits/stdc++.h"
using namespace std;

vector<int> LPS/*Longest Proper Prefix whix is also suffix*/(string s){
    int n = s.length();
    int len = 0;
    vector<int> arr(n);
    arr[0] = len;
    int i = 1;
    while(i<n){
        if(s[i] == s[len]){
            arr[i++] = ++len;
        }else{
            if(len != 0){
                len = arr[len-1];
            }else{
                arr[i++] = 0;
            }
        }
    }
    return arr;
}

int main(){
    // https://practice.geeksforgeeks.org/problems/search-pattern0205/1
    // Worst Case TC --> O(n)
    string pat, txt;
    cin >> pat >> txt;
    vector<int> lps = LPS(pat);
    int m = pat.length();
    int n = txt.length();

    int i = 0, j = 0;
    while((n-i) >= (m-j)){
        if(pat[j] == txt[i])i++,j++;

        if(j == m){
            cout << i-j << " ";
            j = lps[j-1];
        }else if(i<n and pat[j] != txt[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return 0;
}