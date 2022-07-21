#include<bits/stdc++.h>
using namespace std;

int n,m;
int sx,sy,dx,dy;
bool vis[100][100];

void init(){
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            vis[i][j]=0;
}

int dex[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dey[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

int solve(){
    
    vis[sx][sy] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx,sy},0});
    
    while(!q.empty()){

        int x = q.front().first.first;
        int y = q.front().first.second;
        int l = q.front().second;
        q.pop();
        
        if(x == dx && y == dy)return l;
        
        for(int i = 0;i<8;i++){
            
            int xx = x + dex[i];
            int yy = y + dey[i];
            
            if(valid(xx,yy) && !vis[xx][yy]){
                vis[xx][yy] = true;
                q.push({{xx,yy},l+1});

            }
        }  
    }  
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);    
    
    int t; 
    cin>>t;
    while(t--){
        cin>>n>>m;
        cin>>sx>>sy>>dx>>dy;
    
        init();
        cout<<solve()<<endl;
    }
    return 0;
}
