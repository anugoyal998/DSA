// https://leetcode.com/problems/construct-k-palindrome-strings/

class Solution {
public:
    bool canConstruct(string s, int k) {

        int a[26];  // to store the count of charachters
        memset(a,0,sizeof(a));
        int n=s.length();
        if(k>n)return 0;
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        int res=0;
        for(int i=0;i<26;i++)
        {
            // if count is odd, then increment the resultant
            if(a[i]%2)res++;
        }
        return res<=k;
    }
};