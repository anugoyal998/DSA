            }else if(nextDistance == distance[c]){
                parent[c].pb(b);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     print(parent[i]);
    // }
    vi v[n];
    vi deg(n,0);
    loop(i,n){
        for(auto j:parent[i]){
            v[i].pb(j);
            deg[j]++;
        }
    }
    vector<ll> cnt(n,0);
    vi mine(n,1e8);
    vi maxe(n,0);
    queue<int> q;
    for(int i=0;i<n-1;i++){
        if(deg[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:v[node]){
            deg[it]--;
            if(deg[it] == 0 and it != n-1)
                q.push(it);
        }
    }
    q.push(n-1);
    cnt[n-1] = 1;
    mine[n-1] = 0;
    maxe[n-1] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it:v[node]){
            deg[it]--;
            cnt[it] = (cnt[it] + cnt[no