#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3+1;
int n,m;
int arr[N][N];
int tree[4*N][4*N];

void buildy(int nodex,int startx,int endx,int nodey,int starty,int endy){
    if(starty==endy){
        if(startx==endx){
            tree[nodex][nodey] = arr[startx][starty];
        }else{
            tree[nodex][nodey] = tree[2*nodex+1][nodey] + tree[2*nodex+2][nodey];
        }
    }else{
        int mid = (starty+endy)/2;
        buildy(nodex,startx,endx,2*nodey+1,starty,mid);
        buildy(nodex,startx,endx,2*nodey+2,mid+1,endy);
        tree[nodex][nodey] = tree[nodex][2*nodey+1] + tree[nodex][2*nodey+2];
    }
}

void buildx(int nodex,int startx,int endx){
    if(startx==endx){
        buildy(nodex,startx,endx,0,0,m-1);
    }else{
        int mid = (startx+endx)>>1;
        buildx(2*nodex+1,startx,mid);
        buildx(2*nodex+2,mid+1,endx);
        buildy(nodex,startx,endx,0,0,m-1);
    }
}

int queryy(int nodex,int nodey,int starty,int endy,int y1,int y2){
    if(endy<y1 || y2<starty)return 0;
    if(starty==endy){
        return tree[nodex][nodey];
    }else if(y1<=starty && endy<=y2){
        return tree[nodex][nodey];
    }else{
        int mid = (starty+endy)>>1;
        int la = queryy(nodex,2*nodey+1,starty,mid,y1,y2);
        int ra = queryy(nodex,2*nodey+2,mid+1,endy,y1,y2);
        return la+ra;
    }
}

int queryx(int nodex,int startx,int endx,int x1,int y1,int x2,int y2){
    if(endx<x1 || x2<startx)return 0;
    if(startx==endx){
        return queryy(nodex,0,0,m-1,y1,y2);
    }else if(x1<=startx && endx<=x2){
        return queryy(nodex,0,0,m-1,y1,y2);
    }else{
        int mid = (startx+endx)>>1;
        int la = queryx(2*nodex+1,startx,mid,x1,y1,x2,y2);
        int ra = queryx(2*nodex+2,mid+1,endx,x1,y1,x2,y2);
        return la+ra;
    }
}

int32_t main(){
    int q;cin >> n >> q;
    m = n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;cin >> ch;
            if(ch == '*')arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    buildx(0,0,n-1);
    while(q--){
        int y1,x1,y2,x2;cin >> y1 >> x1 >> y2 >> x2;
        y1--,x1--,y2--,x2--;
        cout << queryx(0,0,n-1,y1,x1,y2,x2) << endl;
    }
    return 0;
}