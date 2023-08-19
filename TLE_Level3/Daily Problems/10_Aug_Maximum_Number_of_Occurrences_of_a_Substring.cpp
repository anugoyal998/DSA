// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

class Solution {
    int help(string s,int k,int mid){
        unordered_map<string,int> m;
        string x = "";
        unordered_map<char,int> m1;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            x += s[i];
            m1[s[i]]++;
            if(i>=mid-1){
                if(m1.size() <= k){
                    m[x]++;
                    ans = max(ans,m[x]);
                }
                m1[x[0]]--;
                if(m1[x[0]] == 0)m1.erase(x[0]);
                x.erase(x.begin());
            }
        }
        return ans;
    }
public:
    int maxFreq(string s, int k, int low, int high) {
        int n = s.length();
        int ans = 0;
        for(int i=low;i<=high;i++){
            ans = max(ans,help(s,k,i));
        }
        return ans;
    }
};