#include<iostream>
#include <queue>
using namespace std;

struct Node{
    bool left, right, up, down;
};

int n,m,sX, sY, len, ans;
int arr[1005][1005];
int vis[1005][1005], dis[1005][1005];


Node pipes[1005][1005];
queue<pair<int, int>> Q;


bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void init(){
    ans = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m; j++){
            vis[i][j] = 0;
            dis[i][j] = 0;
        }
    }
    while(!Q.empty())
        Q.pop();
}

void bfs(){  
    dis[sX][sY] = 1;
    vis[sX][sY] = 1;
    
    if(!arr[sX][sY]){
        ans = 0;
        return;
    }
    

    Q.push({sX, sY});
    while(!Q.empty()){

        int p=Q.front().first;
        int q=Q.front().second;
        Q.pop();
        
        
        if(1+dis[p][q]<=len){
            
            /* Row Up */
            if( isValid(p-1, q) && vis[p-1][q] == 0 && pipes[p-1][q].down && pipes[p][q].up ){
                vis[p-1][q] = 1;
                dis[p-1][q] = 1 + dis[p][q];
                ans++;
            
                Q.push({p-1,q});
 
            } 
            
            /* Row Down */
            if( isValid(p+1, q) && vis[p+1][q] == 0 && pipes[p+1][q].up && pipes[p][q].down ){
                vis[p+1][q] = 1;
                dis[p+1][q] = 1 + dis[p][q];
                ans++;
                Q.push({p+1,q});
    
            } 
            
            /* Column Left */
            if( isValid(p, q-1) && vis[p][q-1] == 0 && pipes[p][q-1].right && pipes[p][q].left ){
                vis[p][q-1] = 1;
                dis[p][q-1] = 1 + dis[p][q];
                ans++;
                Q.push({p,q-1});
 
            }          

            /* Column Right */
            if( isValid(p, q+1) && vis[p][q+1] == 0 && pipes[p][q+1].left && pipes[p][q].right ){
                vis[p][q+1] = 1;
                dis[p][q+1] = 1 + dis[p][q];
                ans++;
                Q.push({p,q+1});

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
    cin >> t;
    while(t--){
        
        cin>>n>>m>>sX>>sY>>len;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                
                if( arr[i][j] == 1 ){
                    pipes[i][j].left = true;
                    pipes[i][j].right = true;
                    pipes[i][j].up = true;
                    pipes[i][j].down = true;
                } 
                else if( arr[i][j] == 2 ){
                    pipes[i][j].left = false;
                    pipes[i][j].right = false;
                    pipes[i][j].up = true;
                    pipes[i][j].down = true;
                }
                else if( arr[i][j] == 3 ){
                    pipes[i][j].left = true;
                    pipes[i][j].right = true;
                    pipes[i][j].up = false;
                    pipes[i][j].down = false;                   
                }
                else if( arr[i][j] == 4 ){
                    pipes[i][j].left = false;
                    pipes[i][j].right = true;
                    pipes[i][j].up = true;
                    pipes[i][j].down = false;
                }
                else if( arr[i][j] == 5 ){
                    pipes[i][j].left = false;
                    pipes[i][j].right = true;
                    pipes[i][j].up = false;
                    pipes[i][j].down = true;
                }
                else if( arr[i][j] == 6 ){
                    pipes[i][j].left = true;
                    pipes[i][j].right = false;
                    pipes[i][j].up = false;
                    pipes[i][j].down = true;
                }
                else if( arr[i][j] == 7 ){
                    pipes[i][j].left = true;
                    pipes[i][j].right = false;
                    pipes[i][j].up = true;
                    pipes[i][j].down = false;                   
                }
                else{
                    pipes[i][j].left = false;
                    pipes[i][j].right = false;
                    pipes[i][j].up = false;
                    pipes[i][j].down = false;                   
                }
     
            }
        }
        init();
        bfs();
        cout<<ans<<endl;
    }
    return 0;
}
