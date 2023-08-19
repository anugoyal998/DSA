#include <bits/stdc++.h>

class Node{
  public:
    Node* links[2];
    
    bool containsKey(int num){
        return (links[num] != NULL);
    }
    
    void put(int num,Node * node){
        links[num] = node;
    }
    
    Node* get(int num){
        return links[num];
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = num&(1<<i);
            if(!node->containsKey(bit))node->put(bit,new Node());
            node = node->get(bit);
        }
    }
    
    int maxX(int num){
        int ans = 0;
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = num&(1<<i);
            bit = 1 - bit;
            if(node->containsKey(bit)){
                ans = ans | (1<<i);
                node = node->get(bit);
            }else{
                node = node->get(1-bit);
            }
        }
        return ans;
    }
};


int maxXOR(int n, int m, vector<int> &a, vector<int> &b) 
{
    // Write your code here.   
    Trie t;
    for(auto &i:a)t.insert(i);
    int ans = 0;
    for(auto &i:b){
        ans = max(ans,t.maxX(i));
    }
    return ans;
    
    
    
    
    
    
    
}